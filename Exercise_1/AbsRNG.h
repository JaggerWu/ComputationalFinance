#pragma once
#include<stdio.h>
#include<random>

namespace Exercise_1
{
    class AbsRNG
    {
    private:
        /* data */
    public:
        virtual double operator()() = 0;
        virtual ~AbsRNG() {}
    };

    class MTRNG: public AbsRNG
    {
    private:
        /* data */
        std::mt19937 mt;
    public:
        MTRNG(uint_fast32_t seed);
        virtual double operator()();
        virtual ~MTRNG() {}
    };
}
