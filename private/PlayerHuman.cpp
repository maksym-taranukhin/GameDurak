#include "PlayerHuman.h"

namespace NGameDurak
{
    CPlayerHuman::CPlayerHuman()
    {
    }
    
    CPlayerHuman::~CPlayerHuman()
    {
    }

    CDefinition::EResult CPlayerHuman::makeAMove()
    {
        const Card& card = mMoventController->getCardForMovement();

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