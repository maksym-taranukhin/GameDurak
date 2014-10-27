#pragma once

namespace NGameDurak
{
    class CDefinition
    {
    public:
        enum EResult
        {
            OK,
            WRONG_NUMBER_OF_PLAYERS,
            TOO_MUCH_CARDS,
            WRONG_CARD_FOR_MOVEMENT
        };
    };
}