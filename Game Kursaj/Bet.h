#pragma once
class Bet {
public:
    Bet(int initial = 100);
    bool PlaceBet(int amount);
    bool IsBankrupt() const;
    void Win();
    void Lose();
    void Push();
    int GetBalance() const;

private:
    int m_Balance;
    int m_CurrentBet;
    bool m_IsBankrupt;
};