#pragma once
#include<stdio.h>

#include<Exercise_1/AbsRNG.h>

namespace Exercise_1
{
    class NormRNG
    {
    public:
        virtual double operator ()() const = 0;
        virtual ~NormRNG() {}
    };

    class MoroNormRNG
    {
    private:
        /* data */
        Exercise_1::AbsRNG& absRNG;
    public:
        MoroNormRNG(Exercise_1::AbsRNG& absRNG_);
        virtual double operator ()() const;
        virtual ~MoroNormRNG() {}
    };
} // namespace Exercise_1

