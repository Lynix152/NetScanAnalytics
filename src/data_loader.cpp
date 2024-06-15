#include <stdexcept>
#include "data_loader.h"
#include "csv_loader.h"
#include "json_loader.h"
#include "xml_loader.h"
#include "data_loader_factory.h"

std::vector<std::vector<std::string>> CSVLoader::load(const std::string& filename) {
    return load_csv(filename);
}

std::vector<std::vector<std::string>> JSONLoader::load(const std::string& filename) {
    return load_json(filename);
}

std::vector<std::vector<std::string>> XMLLoader::load(const std::string& filename) {
    return load_xml(filename);
}

std::unique_ptr<DataLoader> DataLoaderFactory::createDataLoader(const std::string& filename) {
    if (filename.substr(filename.find_last_of(".") + 1) == "csv") {
        return std::make_unique<CSVLoader>();
    } else if (filename.substr(filename.find_last_of(".") + 1) == "json") {
        return std::make_unique<JSONLoader>();
    } else if (filename.substr(filename.find_last_of(".") + 1) == "xml") {
        return std::make_unique<XMLLoader>();
    } else {
        throw std::invalid_argument("Unsupported file format");
    }
}
