// #include "pch.h"
#include <iostream>
#include <random>
#include <stdexcept>

// Structure the output from your code into blocks like this.
// Show both by outputting and comments which specific question you are outputting for.
// If there is no output, don't do anything.
// Keep your implementation in .cpp and .h files as usual.

class MTRNG
{
private:
	/* fileds */
	std::mt19937 mt;
public:
	MTRNG(const uint_fast32_t seed);
	~MTRNG();

	double operator()();
};

MTRNG::MTRNG(const uint_fast32_t seed): mt(seed)
{
}

double MTRNG::operator()()
{
	std::uniform_real_distribution<double> dist(0.0, 1.0);
	
	return dist(mt);
}

MTRNG::~MTRNG()
{
}

double InverseNormalCDF(const double u)
{
	if (u < 0 || u > 1)
	{
		throw std::invalid_argument("Please be sure 0 < u < 1");
	}

	double a0 = 2.50662823884, a1 = -18.61500062529, 
		a2 = 41.39119773534, a3 = -25.44106049637;
	
	double b0 = -8.47351093090, b1 = 23.08336743743, 
		b2 = -21.06224101826, b3 = 3.13082909833;
	
	double c0 = 0.3374754822726147, c1 = 0.9761690190917186,
		c2 = 0.1607979714918209, c3 = 0.0276438810333863,
		c4 = 0.0038405729373609, c5 = 0.0003951896511919,
		c6 = 0.0000321767881768, c7 = 0.0000002888167364,
		c8 = 0.0000003960315187;

	double x;
	double r, y = u - 0.5;

	if (std::abs(y) < 0.42)
	{
		r = y * y;
		x = y * (((a3 * r + a2) * r + a1) * r + a0) / 
			((((b3 * r + b2) * r + b1) * r + b0) * r + 1);
	}
	else
	{
		r = u;
		if (y > 0) 
		{
			r = 1 - u;
		}

		r = std::log(-std::log(r));
		x = c0 + r * (c1 + r * (c2 + r * (c3 + r * ( c4 
			+ r * (c5 + r * (c6 + r * (c7 + r * c8)))))));
		
		if (y < 0) 
		{
			x = -x;
		}
	}
	return x;
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
	double u = 1.5;
	std::cout << "When u = " << u << ", the inverse of CDF should be " 
		<< InverseNormalCDF(u) << std::endl;
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
