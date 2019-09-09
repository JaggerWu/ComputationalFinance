#include<iostream>

#include "Gaussian.h"

double getOneUniform()
// Returns one U(0,1) random variable by scaling rand().
{
	return rand() / (double)(RAND_MAX);
}

double getOneGaussianByCLT()
// Returns a single approximately normal random variable - see slides. Note: Quick and dirty.
{
	double result = -6;

	for (unsigned j = 0; j < 12; j++)
	{
		double a = getOneUniform();
		std::cout << "The rand number is " << a << std::endl;
	}
	return result;
}
