// #include "pch.h"
#include <iostream>
#include <random>
#include <stdexcept>

#include <Exercise_1/AbsRNG.h>
#include <Exercise_1/InverseNormCDF.h>

// Structure the output from your code into blocks like this.
// Show both by outputting and comments which specific question you are outputting for.
// If there is no output, don't do anything.
// Keep your implementation in .cpp and .h files as usual.

// Exercise 1.3
class MTRNG
{
private:
	/* fileds */
	std::mt19937 mt;
public:
	MTRNG(const uint_fast32_t seed);
	~MTRNG();

	double operator ()();
};

MTRNG::MTRNG(const uint_fast32_t seed): mt(seed)
{
}

double MTRNG::operator ()()
{
	return mt() / (double)mt.max();
}

MTRNG::~MTRNG()
{
}

/*
	Exercise 1.6
*/
class PreMoroNormRNG
{
private:
	/* data */
	MTRNG mtRNG;
public:
	PreMoroNormRNG();
	~PreMoroNormRNG();

	double operator() ();
};

PreMoroNormRNG::PreMoroNormRNG(): mtRNG(1)
{
}

double PreMoroNormRNG::operator() ()
{
	return Exercise_1::InverseNormalCDF(mtRNG());
}

PreMoroNormRNG::~PreMoroNormRNG()
{
}

void Exercise1()
{	
	// 1.1
	std::mt19937 generator(1);
	
	std::cout << "Exercise 1.1: \n";

	// 1.2

	// 1.3
	uint_fast32_t seed = 1;
	MTRNG mtRNG(seed);
	
	std::cout << "Exercise 1.3: \n";
	std::cout << mtRNG() << std::endl;
	//  ... some questions with no output. you should have nothing here.

	// 1.4.
	std::cout << "Exercise 1.4: \n";
	std::cout << "some output \n";

	// 1.5.
	std::cout << "Exercise 1.5: \n";
	double u = mtRNG();
	std::cout << "When u = " << u << ", the inverse of CDF should be " 
		<< Exercise_1::InverseNormalCDF(u) << std::endl;

	// 1.6
	PreMoroNormRNG preMoroNormRNG;
	
	// 1.7

	// 1.8

	// 1.9

	// 1.10
}

void Exercise2()
{
	// ... output related code to exercise 2.
}


int main()
{
	Exercise1();
	Exercise2();

}
