#pragma once
#include "Card.h"

namespace NGameDurak
{
    class IMovementController
    {
    public:
        virtual const Card& getCardForMovement() = 0;
    };
}