#include "Statistics.h"
#include <iostream>

Statistics::Statistics() : m_Wins(0), m_Losses(0), m_Pushes(0) {}

void Statistics::RecordWin() { ++m_Wins; }

void Statistics::RecordLoss() { ++m_Losses; }

void Statistics::RecordPush() { ++m_Pushes; }

void Statistics::ShowStatistics(const std::string& playerName) const {
    std::cout << "\nStats for " << playerName << ": Wins: " << m_Wins << ", Losses: " << m_Losses << ", Pushes: " << m_Pushes << std::endl;
}