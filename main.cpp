#include<iostream>
#include<stdio.h>
#include<random>

#include "Common/Math.h"
#include "Common/Gaussian.h"
#include "Option/PayOff.h"

int main()
{
    ComplexNumber* tt = new ComplexNumber;

    tt->Set(0.5f, 0.6f);

    delete tt;
    ComplexNumber a(1.0f, 2.0f);
    ComplexNumber b(2.0f, 3.0f);

    *tt = a - b;
    ComplexNumber d = a;
    a += b;

    printf ("The complex number is (%f, %f) \n", tt->re, tt->im);
    delete tt;

    std::cout << (a == b) << std::endl;

    printf ("The complex number is (%f, %f) \n", d.re, d.im);
    printf ("The complex number is (%f, %f) \n", a.re, a.im);

    PayOffCall call_(1.20);

    std::cout << "The strike is" << 1.23 << std::endl;
    std::cout << "The pay off is " << call_(1.21) << std::endl;

    PayOffDoubleDigital test(1.50, 1.30);
    std::cout << "The pay off double digital is " << test(1.21) << std::endl;

    PayOffDoubleDigital test2(DigitalType::lowerLevel, 1.1);
    PayOff* test3 = test2.clone();

    std::cout << "The pay off digital(test2) is " << test2(1.01) << std::endl;
    std::cout << "The pay off digital(test3) is " << test3->operator()(1.01) << std::endl;

    std::cout << "Get gaussian is " << getOneGaussianByCLT()<< std::endl;

    std::mt19937 generator (1);
    std::uniform_real_distribution<double> dis(0.0, 1.0);

    double randomRealBetweenZeroAndOne = dis(generator);
    double randomRealBetweenZeroAndOne2 = dis(generator);

    std::cout << "The random number is " << randomRealBetweenZeroAndOne << std::endl;
    std::cout << "The random number is " << randomRealBetweenZeroAndOne2 << std::endl; 
    
    return EXIT_SUCCESS;
}