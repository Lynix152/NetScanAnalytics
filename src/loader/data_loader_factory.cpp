#include "../include/data_loader_factory.h"
#include "../include/csv_loader.h"
#include "../include/json_loader.h"
#include "../include/xml_loader.h"
#include "../include/Logger.h"
#include <stdexcept>
#include <memory>
#include <string>

std::unique_ptr<DataLoader> DataLoaderFactory::createDataLoader(const std::string& filename) {
    if (filename.find(".csv") != std::string::npos) {
        Logger::getInstance().log(INFO, "CSV file loader created");
        return std::make_unique<CSVLoader>();
    } else if (filename.find(".json") != std::string::npos) {
        Logger::getInstance().log(INFO, "JSON file loader created");
        return std::make_unique<JSONLoader>();
    } else if (filename.find(".xml") != std::string::npos) {
        Logger::getInstance().log(INFO, "XML file loader created");
        return std::make_unique<XMLLoader>();
    } else {
        Logger::getInstance().log(ERROR, "Unsupported file format");
        throw std::runtime_error("Unsupported file format");
    }
}
