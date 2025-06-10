#include <iostream>
#include <vector>
#include <string>
#include <limits> // для numeric_limits
#include "Game.h"

using namespace std;

int main() {
    cout << "\t\tWelcome to Blackjack!\n";

    int numPlayers = 0;
    while (true) {
        cout << "How many players? (1 - 7): ";
        cin >> numPlayers;

        if (cin.fail()) {
            cin.clear(); // Сброс флага ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
            cout << "Invalid input. Please enter a number between 1 and 7.\n";
        }
        else if (numPlayers < 1 || numPlayers > 7) {
            cout << "Please enter a number between 1 and 7.\n";
        }
        else {
            break;
        }
    }

    vector<string> names;
    for (int i = 0; i < numPlayers; ++i) {
        string name;
        while (true) {
            cout << "Enter player " << i + 1 << " name: ";
            cin >> name;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid name. Please try again.\n";
            }
            else if (name.empty()) {
                cout << "Name cannot be empty. Try again.\n";
            }
            else {
                names.push_back(name);
                break;
            }
        }
    }

    try {
        Game aGame(names);
        char again = 'y';
        while (again != 'n' && again != 'N') {
            aGame.Play();
            cout << "\nDo you want to play again? (Y/N): ";
            cin >> again;
        }
    }
    catch (const exception& ex) {
        cerr << "Error occurred: " << ex.what() << endl;
    }
    catch (...) {
        cerr << "Unknown error occurred." << endl;
    }

    cout << "\nThanks for playing! Goodbye!\n";
    return 0;
}