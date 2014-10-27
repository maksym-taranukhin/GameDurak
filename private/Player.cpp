#include "../Player.h"

namespace NGameDurak
{
    size_t IPlayer::addCard(const Card& card)
    {
        return mCardSet.addCard(card);
    }

    const Card IPlayer::getLeastCard() const
    {
        Card leastCard = mCardSet[0];

        const size_t size = mCardSet.emount();
        for (size_t i = 1; i < size; ++i)
        {
            if (mCardSet[i] < leastCard) leastCard = mCardSet[i];
        }

        return leastCard;
    }
}