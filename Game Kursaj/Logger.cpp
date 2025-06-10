#include "Logger.h"

Logger g_Logger; 

Logger::Logger(const std::string& filename) {
    m_LogFile.open(filename, std::ios::out | std::ios::app);
}

Logger::~Logger() {
    if (m_LogFile.is_open())
        m_LogFile.close();
}

void Logger::Log(const std::string& message) {
    if (m_LogFile.is_open())
        m_LogFile << message << std::endl;
}