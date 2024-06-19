#include "../include/xml_loader.h"
#include "../include/Logger.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <tinyxml2.h>

std::vector<std::vector<std::string>> load_xml(const std::string& filename) {
    std::vector<std::vector<std::string>> data;
    tinyxml2::XMLDocument doc;

    if (doc.LoadFile(filename.c_str()) != tinyxml2::XML_SUCCESS) {
        Logger::getInstance().log(CRITICAL, "Cannot open the file to be analyzed");
        throw std::runtime_error("Cannot find file");
    }

    tinyxml2::XMLElement* root = doc.RootElement();
    for (tinyxml2::XMLElement* elem = root->FirstChildElement(); elem != nullptr; elem = elem->NextSiblingElement()) {
        std::vector<std::string> row;
        for (tinyxml2::XMLElement* child = elem->FirstChildElement(); child != nullptr; child = child->NextSiblingElement()) {
            row.push_back(child->GetText());
        }
        data.push_back(row);
    }

    return data;
}
