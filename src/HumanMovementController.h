#pragma once
#include "IMovementController.h"

namespace NGameDurak
{
    class CHumanMovementController : public IMovementController
    {
    public:
        CHumanMovementController();

        ~CHumanMovementController();

        const Card& getCardForMovement(const CPlayerPack& pack);
    };

}