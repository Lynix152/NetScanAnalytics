#include "../../include/csv_loader.h"
#include "../../include/Logger.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::vector<std::vector<std::string>> CSVLoader::load(const std::string &filename) {
    std::vector<std::vector<std::string>> data;
    std::ifstream file(filename);

    if (!file.is_open()) {
        Logger::getInstance().log(CRITICAL, "Cannot open the file to be analyzed");
        throw std::runtime_error("Cannot find file");
    }

    std::string line;

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);

        std::string value;

        while (std::getline(ss, value, ',')) {
            row.push_back(value);
        }
        data.push_back(row);
    }

    file.close();
    return data;
}
