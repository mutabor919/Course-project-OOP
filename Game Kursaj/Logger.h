#pragma once
#include <fstream>
#include <string>

class Logger {
public:
    Logger(const std::string& filename = "game_log.txt");
    ~Logger();
    void Log(const std::string& message);

private:
    std::ofstream m_LogFile;
};

extern Logger g_Logger; // ќбъ€вление глобального объекта