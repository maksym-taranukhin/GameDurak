#include "Card.h"

namespace NGameDurak
{
    bool operator==(const Card& left, const Card& right)
    {
        return left.mRank == right.mRank && left.mSuit == right.mSuit;
    }

    bool operator>(const Card& left, const Card& right)
    {

        return left.mRank > right.mRank;
    }

    bool operator<(const Card& left, const Card& right)
    {
        return left.mRank < right.mRank;
    }

    CCardSet::CCardSet(const size_t emount)
    {
        mCardSet.resize(emount);
    }


    CCardSet::~CCardSet()
    {

    }

    const Card& CCardSet::operator[](size_t value) const
    {
        if (value < 0 || value > mCardSet.size())
            throw;

        return mCardSet[value];
    }

    void CCardSet::removeCard(size_t pos)
    {
        mCardSet.erase(mCardSet.begin() + pos);
    }

    CPack36::CPack36() : CCardSet(36), mTrump()
    {
        init36Pack();
    }

    void CPack36::shake()
    {
        CAlgorithm::shakeArray<Card>(mCardSet);

        mTrump = mCardSet[mCardSet.size() - 1];
    }

    const Card CPack36::takeOneCard()
    {
        Card card = mCardSet[mCardSet.size() - 1];
        mCardSet.pop_back();
        return card;
    }

    void CPack36::init36Pack()
    {
        mCardSet.resize(36);

        generate4Card(Rank::SIX, 0);
        generate4Card(Rank::SEVEN, 4);
        generate4Card(Rank::EIGHT, 8);
        generate4Card(Rank::NINE, 12);
        generate4Card(Rank::TEN, 16);
        generate4Card(Rank::JACK, 20);
        generate4Card(Rank::QUEEN, 24);
        generate4Card(Rank::KING, 28);
        generate4Card(Rank::ACE, 32);
    }

    void CPack36::generate4Card(const Rank& rank, const size_t pos)
    {
        mCardSet[pos].mRank = rank;
        mCardSet[pos].mSuit = (char)3;

        mCardSet[pos + 1].mRank = rank;
        mCardSet[pos + 1].mSuit = (char)4;

        mCardSet[pos + 2].mRank = rank;
        mCardSet[pos + 2].mSuit = (char)5;

        mCardSet[pos + 3].mRank = rank;
        mCardSet[pos + 3].mSuit = (char)6;
    }

    CPack6::CPack6() : CCardSet(6), mFreeSpace(6)
    {

    }
    
    size_t CPack6::addCard(const Card& card)
    {
        mCardSet[6 - mFreeSpace] = card;

        return --mFreeSpace;
    }

} // namespace NGameDurak