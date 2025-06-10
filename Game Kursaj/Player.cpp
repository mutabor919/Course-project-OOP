#include "Player.h"
#include "Logger.h"
#include <iostream>


Player::Player(const string& name) : GenericPlayer(name) {}

Player::~Player() {}

bool Player::IsHitting() const {
    cout << m_Name << ", do you want a hit? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}

bool Player::IsBankrupt() const {
    return m_Bet.IsBankrupt();
}

string Player::GetName() const {
    return m_Name;
}

void Player::PlaceBet() {
    if (m_Bet.IsBankrupt()) {
        cout << m_Name << " has no money left and is out of the game.\n";
        g_Logger.Log(m_Name + " is bankrupt and out of the game.");
        return;
    }

    int amount;
    bool validBet = false;
    while (!validBet) {
        cout << m_Name << ", your balance: " << m_Bet.GetBalance() << ". Enter your bet: ";
        cin >> amount;
        validBet = m_Bet.PlaceBet(amount);
    }
    g_Logger.Log(m_Name + " placed a bet of " + to_string(amount));
}

void Player::ShowStats() {
    m_Stats.ShowStatistics(m_Name);
}

void Player::Win() {
    cout << m_Name << " wins.\n";
    m_Bet.Win();
    m_Stats.RecordWin();
    g_Logger.Log(m_Name + " wins.");
}

void Player::Lose() {
    cout << m_Name << " loses.\n";
    m_Bet.Lose();
    m_Stats.RecordLoss();
    g_Logger.Log(m_Name + " loses.");
}

void Player::Push() {
    cout << m_Name << " pushes.\n";
    m_Bet.Push();
    m_Stats.RecordPush();
    g_Logger.Log(m_Name + " pushes.");
}