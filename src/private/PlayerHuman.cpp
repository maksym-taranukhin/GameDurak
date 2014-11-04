#include "../PlayerHuman.h"
#include "../HumanMovementController.h"

namespace NGameDurak
{
    CPlayerHuman::CPlayerHuman() : mMoventController(new CHumanMovementController)
    {
    }
    
    CPlayerHuman::~CPlayerHuman()
    {
        delete mMoventController;
    }

    CDefinition::EResult CPlayerHuman::makeAMove(Card & card)
    {
        card = mMoventController->getCardForMovement(mCardSet);

        for (size_t i = 0; i < mCardSet.emount(); ++i)
        {
            if (card == mCardSet[i])
            {
                mCardSet.removeCard(i);
                return CDefinition::EResult::OK;
            }
        }

        return CDefinition::EResult::WRONG_CARD_FOR_MOVEMENT;
    }
}