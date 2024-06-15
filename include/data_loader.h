#ifndef DATA_LOADER_H
#define DATA_LOADER_H

#include <vector>
#include <string>

class DataLoader {
public:
    virtual ~DataLoader() = default;
    virtual std::vector<std::vector<std::string>> load(const std::string& filename) = 0;
};

class CSVLoader : public DataLoader {
public:
    std::vector<std::vector<std::string>> load(const std::string& filename) override;
};

class JSONLoader : public DataLoader {
public:
    std::vector<std::vector<std::string>> load(const std::string& filename) override;
};

class XMLLoader : public DataLoader {
public:
    std::vector<std::vector<std::string>> load(const std::string& filename) override;
};

#endif // DATA_LOADER_H
