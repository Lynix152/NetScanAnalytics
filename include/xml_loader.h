#ifndef XML_LOADER_H
#define XML_LOADER_H

#include "data_loader.h"
#include <vector>
#include <string>

class XMLLoader : public DataLoader {
public:
    std::vector<std::vector<std::string>> load(const std::string &filename) override;
};

#endif // XML_LOADER_H
