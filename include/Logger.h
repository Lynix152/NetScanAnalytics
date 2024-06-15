#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

enum LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

class Logger {
public:
    static Logger& getInstance();
    void log(LogLevel level, const std::string &message);

private:
    Logger();
    ~Logger();
    std::ofstream logFile;
};

#endif // LOGGER_H
