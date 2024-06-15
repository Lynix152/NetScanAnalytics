#include "../include/Logger.h"
#include "../include/data_loader_factory.h"
#include "../include/distributor.h"
#include <fstream>
#include <iostream>
#include <mpi.h>

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

int main(int argc, char **argv) {
    Logger::getInstance().log(DEBUG, "DataSpectraX has started, logfile: 'logfile.txt'");
    MPI_Init(&argc, &argv);

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    if (world_rank == 0) {
        printFile("asciiart.txt");
        std::unique_ptr<DataLoader> loader = DataLoaderFactory::createDataLoader("data.csv"); // Change filename to test different formats
        std::vector<std::vector<std::string>> data = loader->load("data.csv");
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
