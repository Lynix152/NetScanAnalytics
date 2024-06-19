#include "data_loader.h"
#include "csv_loader.h"
#include "json_loader.h"
#include "xml_loader.h"
#include "Logger.h"
#include <stdexcept>
#include <iostream>
#include <sstream>

std::vector<std::vector<std::string>> CSVLoader::load(const std::string& filename) {
    return load_csv(filename);
}

std::vector<std::vector<std::string>> JSONLoader::load(const std::string& filename) {
    return load_json(filename);
}

std::vector<std::vector<std::string>> XMLLoader::load(const std::string& filename) {
    return load_xml(filename);
}

// Implementierung der Funktion zum manuellen Laden von Daten
std::vector<std::vector<std::string>> load_data_manually() {
    std::vector<std::vector<std::string>> data;
    std::string line;

    std::cout << "Geben Sie Ihre Daten ein (jede Zeile einzeln, leere Zeile zum Beenden):" << std::endl;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            break;
        }
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string value;
        while (std::getline(ss, value, ',')) {
            row.push_back(value);
        }
        data.push_back(row);
    }
    return data;
}
