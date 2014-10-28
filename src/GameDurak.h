#pragma once
#include <vector>

#include "Player.h"
#include "Card.h"
#include "AdditionalDefinitions.h"

namespace NGameDurak
{
    class CGameDurak
    {
    public:

        CGameDurak();
       
        ~CGameDurak();

        CDefinition::EResult create(const size_t numberOfHumanPlayers, const size_t numberOfAIPlayers);

        void start() const;
    private:

        size_t whoIsFirst() const;
    
    private:

        std::vector<IPlayer*> mPlayers;
        CPack36 mPack;
    };
}