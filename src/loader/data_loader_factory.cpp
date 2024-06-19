#include "../include/data_loader_factory.h"
#include "../include/csv_loader.h"
#include "../include/json_loader.h"
#include "../include/xml_loader.h"
#include <stdexcept>
#include <memory>
#include <string>

std::unique_ptr<DataLoader> DataLoaderFactory::createDataLoader(const std::string& filename) {
    if (filename.find(".csv") != std::string::npos) {
        return std::make_unique<CSVLoader>();
    } else if (filename.find(".json") != std::string::npos) {
        return std::make_unique<JSONLoader>();
    } else if (filename.find(".xml") != std::string::npos) {
        return std::make_unique<XMLLoader>();
    } else {
        throw std::runtime_error("Unsupported file format");
    }
}
