#include "GenericPlayer.h"
#include <iostream>

GenericPlayer::GenericPlayer(const std::string& name) : m_Name(name) {}

GenericPlayer::~GenericPlayer() {}

std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer) {
    os << aGenericPlayer.m_Name << ":\t";
    if (!aGenericPlayer.m_Cards.empty()) {
        for (std::vector<Card*>::const_iterator pCard = aGenericPlayer.m_Cards.begin(); pCard != aGenericPlayer.m_Cards.end(); ++pCard) {
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
    std::cout << m_Name << " busts.\n";
}