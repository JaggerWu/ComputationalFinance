#include<iostream>
#include<stdio.h>
using namespace std;

#include "PayOff.h"

PayOffCall::PayOffCall(double Strike_): strike(Strike_) {}

double PayOffCall::operator() (double Spot_) const
{
    return max(Spot_ - strike, 0.0);
}

PayOffPut::PayOffPut(double Strike_): strike(Strike_) {}

double PayOffPut::operator() (double Spot_) const
{
    return max(strike - Spot_, 0.0);
}
