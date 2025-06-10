#pragma once
#include <string>

class Statistics {
public:
    Statistics();
    void RecordWin();
    void RecordLoss();
    void RecordPush();
    void ShowStatistics(const std::string& playerName) const;

private:
    int m_Wins;
    int m_Losses;
    int m_Pushes;
};