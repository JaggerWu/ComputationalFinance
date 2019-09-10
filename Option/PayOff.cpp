#include<iostream>
#include<stdio.h>
using namespace std;

#include "PayOff.h"

PayOffCall::PayOffCall(double Strike_): strike(Strike_) {}

double PayOffCall::operator() (double Spot_) const
{
    return max(Spot_ - strike, 0.0);
}

PayOff* PayOffCall::clone() const
{
	return new PayOffCall(*this);
}

PayOffPut::PayOffPut(double Strike_): strike(Strike_) {}

double PayOffPut::operator() (double Spot_) const
{
    return max(strike - Spot_, 0.0);
}

PayOff* PayOffPut::clone() const
{
	return new PayOffPut(*this);
}

PayOffDigital::PayOffDigital(DigitalType digitalType_, double level_)
{
	type = digitalType_;
	level = level_;
}

double PayOffDigital::operator()(double Spot_) const
{
	if(type == DigitalType::lowerLevel)
	{
		return Spot_ <= level ? 0 : 1;
	}
	else
	{
		return Spot_ >= level ? 0 : 1;
	}
}

PayOff* PayOffDigital::clone() const
{
	return new PayOffDigital(*this);
}

PayOffDoubleDigital::PayOffDoubleDigital(double lowerLevel_, double upperLevel_) : lowerLevel(lowerLevel_), upperLevel(upperLevel_)
{
}

double PayOffDoubleDigital::operator () (double Spot) const
{
	if (Spot <= lowerLevel || Spot >= upperLevel) // -|| means or.
	{
		return 0;
	}

	return 1;
}

PayOff* PayOffDoubleDigital::clone() const
{
	return new PayOffDoubleDigital(*this);
}
