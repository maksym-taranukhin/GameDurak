#pragma once
#include "Card.h"

namespace NGameDurak
{
    class IMovementController
    {
    public:
        virtual const Card& getCardForMovement(const CPlayerPack& pack) = 0;
    };
}