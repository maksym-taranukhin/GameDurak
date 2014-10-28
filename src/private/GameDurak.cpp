#include "../GameDurak.h"
#include "../PlayerAI.h"
#include "../PlayerHuman.h"

namespace NGameDurak
{
    CGameDurak::CGameDurak()
    {
    }


    CGameDurak::~CGameDurak()
    {
    }

    CDefinition::EResult CGameDurak::create(const size_t numberOfHumanPlayers, const size_t numberOfAIPlayers)
    {
        const size_t totalPlayers = numberOfHumanPlayers + numberOfAIPlayers;

        if (totalPlayers < 2 || totalPlayers > 6) return CDefinition::EResult::WRONG_NUMBER_OF_PLAYERS;


        mPlayers.resize(numberOfHumanPlayers, new CPlayerHuman());

        mPlayers.resize(totalPlayers, new CPlayerAI());
        
        mPack.shake();

        for (size_t i = 0; i < totalPlayers; ++i)
        {
            for (size_t j = 0; j < 6; ++j)
                mPlayers[i]->addCard(mPack.takeOneCard());
        }

        return CDefinition::EResult::OK;
    }

    void CGameDurak::start() const
    {
        const size_t numOfPlayer = whoIsFirst();

        for (size_t i = 0; i < mPlayers.size(); ++i)
        {
            mPlayers[i]->makeAMove();
        }

    }

    size_t CGameDurak::whoIsFirst() const
    {
        size_t numOfPlayer = 0;

        Card leastCard = mPlayers[0]->getLeastCard();
        if (leastCard.mRank == Rank::SIX) return numOfPlayer;

        const size_t emountOfPlayers = mPlayers.size();
        for (size_t i = 1; i < emountOfPlayers; ++i)
        {
            const Card leastCardAnotherPlayer = mPlayers[i]->getLeastCard();
            if (leastCardAnotherPlayer < leastCard)
            {
                leastCard = leastCardAnotherPlayer;
                numOfPlayer = i;

                if (leastCard.mRank == Rank::SIX) return numOfPlayer;
            }
        }

        return numOfPlayer;
    }
}