#ifndef SIMPLEMC_H
#define SIMPLEMC_H

// #include "Option/Vanilla.h"
#include "Option/Vanilla.h"

// Now takes a VanillaOption object and no Expiry (since the option holds it)
double simpleMC(
    const VanillaOption& theOption,
    double spot,
    double sigma,
    double r,
    unsigned long NumberOfPaths
);

#endif
