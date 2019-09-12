#ifndef VANILLA_H
#define VANILLA_H

#include "PayOff.h"

class VanillaOption
{
public:
    VanillaOption(const PayOff& ThePayOff, double expiry);
    double getExpiry() const;
    double optionPayoff(double Spot) const;

    // -The rule of three
    VanillaOption(const VanillaOption& original); // -Copy
    ~VanillaOption(); // -Destructor
    VanillaOption& operator=(const VanillaOption& original); // -Assignment
private:
    double expiry;
    PayOff* thePayoffPtr;
};

#endif