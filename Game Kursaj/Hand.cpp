#include "Hand.h"
#include <vector>

Hand::Hand() {
    m_Cards.reserve(7);
}

Hand::~Hand() {
    Clear();
}

void Hand::Add(Card* pCard) {
    m_Cards.push_back(pCard);
}

void Hand::Clear() {
    for (std::vector<Card*>::iterator iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
        delete* iter;
        *iter = nullptr;
    }
    m_Cards.clear();
}

int Hand::GetTotal() const {
    if (m_Cards.empty()) return 0;
    if (m_Cards[0]->GetValue() == 0) return 0;

    int total = 0;
    bool containsAce = false;

    for (std::vector<Card*>::const_iterator iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
        total += (*iter)->GetValue();
        if ((*iter)->GetValue() == Card::ACE) containsAce = true;
    }

    if (containsAce && total <= 11) total += 10;

    return total;
}