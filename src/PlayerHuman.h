#pragma once
#include "Player.h"
#include "IMovementController.h"

namespace NGameDurak
{
    class CPlayerHuman : public IPlayer
    {
    public:
        CPlayerHuman();

        ~CPlayerHuman();

        CDefinition::EResult makeAMove(Card & card);

    private:

        IMovementController *mMoventController;
    };

}