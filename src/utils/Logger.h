#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <sstream>
#include <string>
#include <mutex>

class Logger {
public:
    enum LogLevel {
        INFO,
        WARNING,
        ERROR,
        NONE // No logging
    };

private:
    static LogLevel currentLogLevel; // Current global log level
    static std::mutex logMutex;      // Mutex for thread safety
    std::ostringstream buffer;       // Buffer for streaming messages
    LogLevel activeLogLevel;         // Log level for this instance

public:
    // Constructor for a specific log level
    explicit Logger(LogLevel level) : activeLogLevel(level) {}

    // Destructor to flush the log message
    ~Logger() {
        if (shouldLog()) {
            std::lock_guard<std::mutex> lock(logMutex);
            std::cout << "[" << getLogLevelName(activeLogLevel) << "]: " << buffer.str() << std::endl;
        }
    }

    // Overload the << operator for streaming
    template <typename T>
    Logger& operator<<(const T& message) {
        if (shouldLog()) {
            buffer << message;
        }
        return *this;
    }

    // Static method to set the global log level
    static void setLogLevel(LogLevel level) {
        std::lock_guard<std::mutex> lock(logMutex);
        currentLogLevel = level;
    }

    // Static methods to create loggers for specific levels
    static Logger logInfo() { return Logger(INFO); }
    static Logger logWarning() { return Logger(WARNING); }
    static Logger logError() { return Logger(ERROR); }

private:
    // Determines if the current log level should log
    bool shouldLog() const {
        return activeLogLevel >= currentLogLevel;
    }

    // Converts log level to string
    static std::string getLogLevelName(LogLevel level) {
        switch (level) {
            case INFO: return "INFO";
            case WARNING: return "WARNING";
            case ERROR: return "ERROR";
            case NONE: return "NONE";
            default: return "UNKNOWN";
        }
    }
};

#endif // LOGGER_H