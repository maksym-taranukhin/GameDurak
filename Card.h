#pragma once
#include <vector>
#include <string>

#include "Algorithm.h"

namespace NGameDurak
{
    enum Rank
    {
        SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE 
    };

    struct Card
    {
        char mSuit; 
        Rank mRank;

        friend bool operator==(const Card& left, const Card& right);

        friend bool operator>(const Card& left, const Card& right);

        friend bool operator<(const Card& left, const Card& right);
    };

    class CCardSet
    {
    public:

        CCardSet(const size_t emount);

        ~CCardSet();

    public:

        const Card& operator[](size_t) const;

        void removeCard(size_t pos);

    protected:

        std::vector<Card> mCardSet;
    };

    class CPack36 : public CCardSet
    {
    public:

        CPack36();

        void shake();

        const Card takeOneCard();

        size_t size() const { return mCardSet.size(); }

        Card getTrump() const { return mTrump; }

    private:

        void init36Pack();

        void generate4Card(const Rank& rank, const size_t pos);

    private:

        Card mTrump;
    };

    class CPack6 : public CCardSet
    {
    public:

        CPack6();

        size_t addCard(const Card& card);

        size_t emount() const { return 6 - mFreeSpace; }

    private:

        size_t mFreeSpace;
    };
} //namespace NGameDurak