#include "Game.h"
#include <iostream>
#include <vector>
#include <string>
#include "Deck.h"
#include "House.h"
#include "Player.h"
#include "Logger.h"
#include "GenericPlayer.h"

using namespace std;

Game::Game(const vector<string>& names) {
    for (vector<string>::const_iterator pName = names.begin(); pName != names.end(); ++pName) {
        m_Players.push_back(Player(*pName));
    }
    srand(static_cast<unsigned int>(time(0)));
    m_Deck.Populate();
    m_Deck.Shuffle();
}

Game::~Game() {}

void Game::Play() {
    for (vector<Player>::iterator pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
        pPlayer->PlaceBet();
    }

    for (int i = 0; i < 2; ++i) {
        for (vector<Player>::iterator pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
            m_Deck.Deal(*pPlayer);
        }
        m_Deck.Deal(m_House);
    }

    m_House.FlipFirstCard();

    for (vector<Player>::iterator pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
        cout << *pPlayer << endl;
    }

    cout << m_House << endl;

    for (vector<Player>::iterator pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
        m_Deck.AdditionalCards(*pPlayer);
    }

    m_House.FlipFirstCard();
    cout << endl << m_House;
    m_Deck.AdditionalCards(m_House);

    if (m_House.IsBusted()) {
        for (vector<Player>::iterator pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
            if (!pPlayer->IsBusted()) pPlayer->Win();
        }
    }
    else {
        for (vector<Player>::iterator pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
            if (!pPlayer->IsBusted()) {
                if (pPlayer->GetTotal() > m_House.GetTotal())
                    pPlayer->Win();
                else if (pPlayer->GetTotal() < m_House.GetTotal())
                    pPlayer->Lose();
                else
                    pPlayer->Push();
            }
        }
    }

    for (vector<Player>::iterator pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
        pPlayer->ShowStats();
    }

    for (auto& player : m_Players) {
        player.Clear();
    }
    m_House.Clear();

    for (auto it = m_Players.begin(); it != m_Players.end();) {
        if (it->IsBankrupt()) {
            cout << it->GetName() << " is bankrupt and removed from the game.\n";
            g_Logger.Log(it->GetName() + " is bankrupt and removed from the game.");
            it = m_Players.erase(it);
        }
        else {
            ++it;
        }
    }

    if (m_Players.empty()) {
        cout << "All players are bankrupt. Game over.\n";
        exit(0);
    }
}