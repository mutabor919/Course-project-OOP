#pragma once
#include <vector>
#include "Player.h"
#include "House.h"
#include "Deck.h"

class Game {
public:
    Game(const std::vector<std::string>& names);
    ~Game();

    void Play();

private:
    Deck m_Deck;
    House m_House;
    std::vector<Player> m_Players;
};