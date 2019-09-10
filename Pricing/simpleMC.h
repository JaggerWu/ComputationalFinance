#pragma once

#include "Option/Vanilla.h"

// Now takes a VanillaOption object and no Expiry (since the option holds it)
double simpleMC(const VanillaOption& theOption,
	double spot,
	double sigma,
	double r,
	unsigned long NumberOfPaths);
