#include "../HumanMovementController.h"

namespace NGameDurak
{
    CHumanMovementController::CHumanMovementController()
    {
    }

    CHumanMovementController::~CHumanMovementController()
    {
    }

    const Card& CHumanMovementController::getCardForMovement(const CPlayerPack& pack)
    {
        // TODO: Show player card pack and offer to chose the card

        return pack[0];
    }
}