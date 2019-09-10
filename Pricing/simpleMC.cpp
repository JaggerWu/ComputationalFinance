#include <cmath> // exp, sqrt

#include "simpleMC.h"
#include "Common/Gaussian.h"
#include "Option/Vanilla.h"

double simpleMC(const VanillaOption& theOption,
	double spot,
	double sigma,
	double r,
	unsigned long int NumberOfPaths)
// Estimates price of payoff in the Black-Scholes model.
{	
	double expiry = theOption.getExpiry(); // - new, get the expiry.
	double var = sigma * sigma * expiry;
	double vol = sqrt(var);
	double movedSpot = spot * exp(r * expiry - 0.5 * var);
	double runningSum = 0;

	for (unsigned long int i = 0; i < NumberOfPaths; i++)
	{
		double thisSpot = movedSpot * exp(vol * getOneGaussianByCLT());
		double thisPayOff = theOption.optionPayoff(thisSpot);

		runningSum += thisPayOff;
	}

	return exp(-r * expiry) * runningSum / NumberOfPaths;
}
