#pragma once
#include "Hand.h"
#include "GenericPlayer.h"

class Deck : public Hand {
public:
    Deck();
    virtual ~Deck();

    void Populate();
    void Shuffle();
    void Deal(Hand& aHand);
    void AdditionalCards(GenericPlayer& aGenericPlayer);
};