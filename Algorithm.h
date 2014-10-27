#pragma once
#include <ctime>

#include "Card.h"

namespace NGameDurak
{
    class CAlgorithm
    {
    public:
        template <class T>
        static void shakeArray(std::vector<T> & arr);
    };

    template <class T>
    static void CAlgorithm::shakeArray(std::vector<T> & arr)
    {
        std::srand(static_cast<unsigned int>(std::time(0)));

        size_t size = arr.size();
        for (size_t i = 0; i < size; ++i)
        {
            int rndIndex = std::rand() % 36;

            T tmp = arr[i];
            arr[i] = arr[rndIndex];
            arr[rndIndex] = tmp;
        }
    }
}
