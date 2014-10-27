#pragma once
#include "IMovementController.h"

namespace NGameDurak
{
    class HumanMovementController : public IMovementController
    {
    public:
        HumanMovementController();

        ~HumanMovementController();

        const Card& getCardForMovement();
    };

}