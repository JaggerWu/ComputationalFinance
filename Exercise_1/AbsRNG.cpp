#include<random>
#include<stdio.h>

#include<Exercise_1/AbsRNG.h>

Exercise_1::MTRNG::MTRNG(uint_fast32_t seed): mt(seed)
{
}

double Exercise_1::MTRNG::operator()()
{
    return mt() / (double)mt.max();
}
