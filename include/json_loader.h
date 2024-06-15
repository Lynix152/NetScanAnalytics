#ifndef JSON_LOADER_H
#define JSON_LOADER_H

#include "data_loader.h"
#include <vector>
#include <string>

class JSONLoader : public DataLoader {
public:
    std::vector<std::vector<std::string>> load(const std::string &filename) override;
};

#endif // JSON_LOADER_H
