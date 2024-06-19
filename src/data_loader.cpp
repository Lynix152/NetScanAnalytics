#include "../include/data_loader.h"
#include "../include/csv_loader.h"
#include "../include/json_loader.h"
#include "../include/xml_loader.h"
#include "../include/Logger.h"
#include <stdexcept>

// Entfernen Sie die Definition von createDataLoader aus dieser Datei.
std::vector<std::vector<std::string>> CSVLoader::load(const std::string& filename) {
    return load_csv(filename);
}

std::vector<std::vector<std::string>> JSONLoader::load(const std::string& filename) {
    return load_json(filename);
}

std::vector<std::vector<std::string>> XMLLoader::load(const std::string& filename) {
    return load_xml(filename);
}
