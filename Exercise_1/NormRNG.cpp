#include <random>
#include <stdio.h>

#include <Exercise_1/NormRNG.h>
#include <Exercise_1/InverseNormCDF.h>

Exercise_1::MoroNormRNG::MoroNormRNG(Exercise_1::AbsRNG& absRNG_): absRNG(absRNG_)
{
}

double Exercise_1::MoroNormRNG::operator ()() const
{
    return Exercise_1::InverseNormalCDF(absRNG());
}