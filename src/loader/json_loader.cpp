#include "../../include/json_loader.h"
#include "../../include/Logger.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <nlohmann/json.hpp>
#include <iostream>

std::vector<std::vector<std::string>> load_json(const std::string &filename) {
    std::vector<std::vector<std::string>> data;
    std::ifstream file(filename);

    if (!file.is_open()) {
        Logger::getInstance().log(CRITICAL, "Cannot open the file to be analyzed");
        std::cout << "Program has to interrupt - no json file" << std::endl;
        abort();
    }

    nlohmann::json jsonData;
    file >> jsonData;

    for (const auto& item : jsonData) {
        std::vector<std::string> row;
        for (const auto& element : item) {
            row.push_back(element.get<std::string>());
        }
        data.push_back(row);
    }

    file.close();
    return data;
}
