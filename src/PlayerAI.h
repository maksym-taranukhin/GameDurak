#pragma once
#include "Player.h"
#include "IMovementController.h"

namespace NGameDurak
{
    class CPlayerAI : public IPlayer
    {
    public:
        CPlayerAI();

        ~CPlayerAI();

        CDefinition::EResult makeAMove(Card & card);

    private:

        IMovementController *mMoventController;
    };
}
