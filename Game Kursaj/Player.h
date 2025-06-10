#pragma once
#include <string>
#include "GenericPlayer.h"
#include "Bet.h"
#include "Statistics.h"

class Player : public GenericPlayer {
public:
    Player(const std::string& name = "");
    virtual ~Player();

    virtual bool IsHitting() const;
    void Win();
    void Lose();
    void Push();
    void PlaceBet();
    void ShowStats();
    bool IsBankrupt() const;
    std::string GetName() const;

private:
    Bet m_Bet;
    Statistics m_Stats;
};