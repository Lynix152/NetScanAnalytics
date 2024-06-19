#include "../include/Logger.h"
#include <iostream>

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

Logger::Logger() {
    logFile.open("logfile.txt", std::ios::out | std::ios::app);
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::log(LogLevel level, const std::string &message) {
    if (logFile.is_open()) {
        logFile << "[" << level << "] " << message << std::endl;
    } else {
        std::cerr << "Log file is not open!" << std::endl;
    }
}
