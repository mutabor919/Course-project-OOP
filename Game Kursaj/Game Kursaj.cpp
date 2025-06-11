#include <iostream>
#include <vector>
#include <string>
#include "Game.h"

void clearInputBuffer() {
    std::cin.clear();
    while (std::cin.get() != '\n') continue;
}

int getNumberOfPlayers() {
    int numPlayers = 0;
    bool validInput = false;

    while (!validInput) {
        std::cout << "How many players? (1 - 7): ";
        if (!(std::cin >> numPlayers)) {
            std::cout << "Invalid input. Please enter a number between 1 and 7.\n";
            clearInputBuffer();
        }
        else if (numPlayers < 1 || numPlayers > 7) {
            std::cout << "Number of players must be between 1 and 7.\n";
        }
        else {
            validInput = true;
        }
    }

    return numPlayers;
}

char getPlayAgainResponse() {
    char again;
    bool validInput = false;

    while (!validInput) {
        std::cout << "\nDo you want to play again? (Y/N): ";
        std::cin >> again;

        if (again == 'y' || again == 'Y' || again == 'n' || again == 'N') {
            validInput = true;
        }
        else {
            std::cout << "Invalid input. Please enter Y or N.\n";
            clearInputBuffer();
        }
    }

    return again;
}

int main() {
    std::cout << "Welcome to Blackjack!\n";

    int numPlayers = getNumberOfPlayers();

    std::vector<std::string> names;
    std::string name;
    for (int i = 0; i < numPlayers; ++i) {
        std::cout << "Enter player name: ";
        std::cin >> name;
        names.push_back(name);
    }

    std::cout << std::endl;
    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N') {
        aGame.Play();
        again = getPlayAgainResponse();
    }

    return 0;
}
