#ifndef DATA_LOADER_H
#define DATA_LOADER_H

#include <vector>
#include <string>

class DataLoader {
public:
    virtual std::vector<std::vector<std::string>> load(const std::string &filename) = 0;
    virtual ~DataLoader() = default;
};

#endif // DATA_LOADER_H
