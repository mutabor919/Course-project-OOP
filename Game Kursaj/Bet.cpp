#include "Bet.h"
#include <iostream>
using namespace std;

Bet::Bet(int initial) : m_Balance(initial), m_CurrentBet(0), m_IsBankrupt(false) {}

bool Bet::PlaceBet(int amount) {
    if (m_IsBankrupt) {
        cout << "You have no money left. You are out of the game.\n";
        return false;
    }
    if (amount > m_Balance) {
        cout << "Bet cannot be greater than your current balance (" << m_Balance << ").\n";
        return false;
    }
    if (amount <= 0) {
        cout << "Bet must be a positive amount.\n";
        return false;
    }
    m_CurrentBet = amount;
    m_Balance -= amount;
    return true;
}

bool Bet::IsBankrupt() const {
    return m_Balance == 0;
}

void Bet::Win() {
    if (m_IsBankrupt) return;
    m_Balance += m_CurrentBet * 2;
    m_CurrentBet = 0;
}

void Bet::Lose() {
    if (m_IsBankrupt) return;
    m_CurrentBet = 0;
}

void Bet::Push() {
    if (m_IsBankrupt) return;
    m_Balance += m_CurrentBet;
    m_CurrentBet = 0;
}

int Bet::GetBalance() const {
    return m_Balance;
}