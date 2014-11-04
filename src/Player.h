#pragma once
#include "Card.h"
#include "AdditionalDefinitions.h"
#include <iostream>

namespace NGameDurak
{
    class IPlayer
    {
    public:

        size_t cardEmount() const { return mCardSet.emount(); }

        size_t addCard(const Card& card);

        const Card getLeastCard() const;

        virtual CDefinition::EResult makeAMove(Card & card) = 0;

    protected:

        CPlayerPack mCardSet;
    };

}