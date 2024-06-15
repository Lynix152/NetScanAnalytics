#ifndef DATA_LOADER_FACTORY_H
#define DATA_LOADER_FACTORY_H

#include "data_loader.h"
#include <memory>
#include <string>

class DataLoaderFactory {
public:
    static std::unique_ptr<DataLoader> createDataLoader(const std::string &filename);
};

#endif // DATA_LOADER_FACTORY_H
