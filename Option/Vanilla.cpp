#include <iostream>

#include "Vanilla.h"

VanillaOption::VanillaOption(const PayOff& ThePayoff, double expiry) : expiry(expiry)
{
	// std::cout << "Vanilla Construction \n";
	thePayoffPtr = ThePayoff.clone();
}

double VanillaOption::getExpiry() const
{
	return expiry;
}

double VanillaOption::optionPayoff(double spot) const
{
	return (*thePayoffPtr)(spot);
	// return ThePayOffPtr->operator()(Spot); // -Alternative. 

}

VanillaOption::VanillaOption(const VanillaOption& original) : expiry(original.expiry) , thePayoffPtr(original.thePayoffPtr->clone())
// -Copy
{
	//std::cout << "Vanilla Copy \n";

	// - Alternative solution:
	//expiry = original.expiry;
	//thePayoffPtr = original.thePayoffPtr->clone();
}

VanillaOption::~VanillaOption()
// -Destructor
{
	// std::cout << "Vanilla Destructor \n";
	delete thePayoffPtr;
}

VanillaOption& VanillaOption::operator=(const VanillaOption &original)
// Assignment
{
	// std::cout << "Vanilla Assignment  \n";

	 // - "this" is a pointer to the object calling.
	 // - below their adresses are being compared.
	if (this != &original) // -Not equal. What could happen if we did not have this check? Try removing it and produce an issue.
	{
		expiry = original.expiry;
		delete thePayoffPtr;
		thePayoffPtr = original.thePayoffPtr->clone();
	}
	
	return *this;
}
