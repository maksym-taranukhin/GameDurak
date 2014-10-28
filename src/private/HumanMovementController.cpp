#include "../HumanMovementController.h"

namespace NGameDurak
{
    HumanMovementController::HumanMovementController()
    {
    }

    HumanMovementController::~HumanMovementController()
    {
    }

    const Card& HumanMovementController::getCardForMovement(const CPlayerPack& pack)
    {
        // TODO: resive a player's pack here for decidion!!!

        return pack[0];
    }
}