#include "Logger.h"

Logger::LogLevel Logger::currentLogLevel = Logger::NONE; // Default log level is INFO
std::mutex Logger::logMutex;                             // Mutex for thread safety