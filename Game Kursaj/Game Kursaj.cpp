//Упрощенная версия игры Blackjack: от одного до семи игроков
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

#include <fstream>

// Класс ставок
class Bet {
public:
    Bet(int initial = 100) : m_Balance(initial), m_CurrentBet(0), m_IsBankrupt(false) {}

    // Поставить ставку
    bool PlaceBet(int amount) {
        if (m_IsBankrupt) {
            std::cout << "You have no money left. You are out of the game.\n";
            return false;
        }

        if (amount > m_Balance) {
            std::cout << "Bet cannot be greater than your current balance (" << m_Balance << ").\n";
            return false;
            exit(0);
        }

        if (amount <= 0) {
            std::cout << "Bet must be a positive amount.\n";
            return false;
           
        }

        m_CurrentBet = amount;
        m_Balance -= amount;

        return true;
    }

    bool IsBankrupt() const {
        return m_Balance == 0;
    }

    // Победа
    void Win() {
        if (m_IsBankrupt) return;
        m_Balance += m_CurrentBet * 2;
        m_CurrentBet = 0;
    }

    // Поражение
    void Lose() {
        if (m_IsBankrupt) return;
        m_CurrentBet = 0;
    }

    // Ничья
    void Push() {
        if (m_IsBankrupt) return;
        m_Balance += m_CurrentBet;
        m_CurrentBet = 0;
    }

    int GetBalance() const {
        return m_Balance;
    }


private:
    int m_Balance;
    int m_CurrentBet;
    bool m_IsBankrupt;
};