#include "../include/data_loader.h"
#include "../include/Logger.h"
#include "../include/csv_loader.h"
#include "../include/json_loader.h"
#include "../include/xml_loader.h"
#include <memory>
#include <stdexcept>
#include <algorithm>

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
    auto dot_pos = filename.find_last_of('.');
    if (dot_pos == std::string::npos) {
        Logger::getInstance().log(CRITICAL, "File has no extension: " + filename);
        throw std::runtime_error("File has no extension");
    }

    std::string extension = filename.substr(dot_pos + 1);
    std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);

    if (extension == "csv") {
        return std::make_unique<CSVLoader>();
    } else if (extension == "json") {
        return std::make_unique<JSONLoader>();
    } else if (extension == "xml") {
        return std::make_unique<XMLLoader>();
    } else {
        Logger::getInstance().log(CRITICAL, "Unsupported file extension: " + extension);
        throw std::runtime_error("Unsupported file extension");
    }
}
