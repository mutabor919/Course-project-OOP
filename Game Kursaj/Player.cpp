#include "Player.h"
#include "Logger.h"
#include <iostream>


Player::Player(const std::string& name) : GenericPlayer(name) {}

Player::~Player() {}

bool Player::IsHitting() const {
    std::cout << m_Name << ", do you want a hit? (Y/N): ";
    char response;
    std::cin >> response;

    while (true) {
        if (response == 'y' || response == 'Y') {
            return true;
        }
        else if (response == 'n' || response == 'N') {
            return false;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Invalid input. Please enter Y or N: ";
            std::cin >> response;
        }
    }
}

bool Player::IsBankrupt() const {
    return m_Bet.IsBankrupt();
}

std::string Player::GetName() const {
    return m_Name;
}

void Player::PlaceBet() {
    if (m_Bet.IsBankrupt()) {
        std::cout << m_Name << " has no money left and is out of the game.\n";
        g_Logger.Log(m_Name + " is bankrupt and out of the game.");
        return;
    }

    int amount;
    bool validBet = false;
    while (!validBet) {
        std::cout << m_Name << ", your balance: " << m_Bet.GetBalance() << ". Enter your bet: ";
        std::cin >> amount;
        validBet = m_Bet.PlaceBet(amount);
    }
    g_Logger.Log(m_Name + " placed a bet of " + std::to_string(amount));
}

void Player::ShowStats() {
    m_Stats.ShowStatistics(m_Name);
}

void Player::Win() {
    std::cout << m_Name << " wins.\n";
    m_Bet.Win();
    m_Stats.RecordWin();
    g_Logger.Log(m_Name + " wins.");
}

void Player::Lose() {
    std::cout << m_Name << " loses.\n";
    m_Bet.Lose();
    m_Stats.RecordLoss();
    g_Logger.Log(m_Name + " loses.");
}

void Player::Push() {
    std::cout << m_Name << " pushes.\n";
    m_Bet.Push();
    m_Stats.RecordPush();
    g_Logger.Log(m_Name + " pushes.");
}