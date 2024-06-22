#include "Logger.h"
#include "data_loader_factory.h"
#include "distributor.h"
#include "data_loader.h"
#include <mpi.h>
#include <iostream>
#include <fstream>
#include <analysis.h>
#include <unistd.h>

void printFile(const std::string &filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        Logger::getInstance().log(ERROR, "Error while opening the ASCII File");
    }
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
}

void checkdir() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        std::cout << "Current working dir: " << cwd << std::endl;
    } else {
        perror("getcwd() error");
    }
}

int main(int argc, char **argv) {
    Logger::getInstance().log(DEBUG, "DataSpectraX has started, logfile: 'logfile.txt'");
    MPI_Init(&argc, &argv);

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    if (world_rank == 0) {
        printFile("asciiart.txt");
        checkdir();

        std::vector<std::vector<std::string>> data;
        std::cout << "Wählen Sie die Datenlade-Methode: \n1. Datei\n2. Manuell\n";
        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Ignoriert das newline-Zeichen nach der Zahleneingabe

        if (choice == 1) {
            std::string filepath = "/home/mathias/CLionProjects/NetScanAnalytics/data.csv"; // Oder verwenden Sie den absoluten Pfad: "/full/path/to/data.csv"
            std::unique_ptr<DataLoader> loader = DataLoaderFactory::createDataLoader(filepath); // Dateiname anpassen, um verschiedene Formate zu testen
            data = loader->load(filepath);
        } else if (choice == 2) {
            data = load_data_manually();
        } else {
            std::cerr << "Ungültige Auswahl" << std::endl;
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        distribute_data(data, world_size, world_rank);
    }

    MPI_Barrier(MPI_COMM_WORLD);
    if (world_rank != 0) {
        std::vector<std::vector<std::string>> local_data = receive_data(world_rank);
        analysis(local_data, world_size, world_rank);
    }

    MPI_Finalize();
    Logger::getInstance().log(DEBUG, "Program is done");
    return 0;
}
