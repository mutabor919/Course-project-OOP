#include "GenericPlayer.h"
#include <iostream>

GenericPlayer::GenericPlayer(const string& name) : m_Name(name) {}

GenericPlayer::~GenericPlayer() {}

ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer) {
    os << aGenericPlayer.m_Name << ":\t";
    if (!aGenericPlayer.m_Cards.empty()) {
        for (vector<Card*>::const_iterator pCard = aGenericPlayer.m_Cards.begin(); pCard != aGenericPlayer.m_Cards.end(); ++pCard) {
            os << *(*pCard) << "\t";
        }
        if (aGenericPlayer.GetTotal() != 0) os << "(" << aGenericPlayer.GetTotal() << ")";
    }
    else os << "<empty>";
    return os;
}

bool GenericPlayer::IsBusted() const {
    return GetTotal() > 21;
}

void GenericPlayer::Bust() const {
    cout << m_Name << " busts.\n";
}