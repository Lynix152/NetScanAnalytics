#ifndef CSV_LOADER_H
#define CSV_LOADER_H

#include "data_loader.h"
#include <vector>
#include <string>

class CSVLoader : public DataLoader {
public:
    std::vector<std::vector<std::string>> load(const std::string &filename) override;
};

#endif // CSV_LOADER_H
