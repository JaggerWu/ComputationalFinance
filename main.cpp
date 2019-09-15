#include<iostream>
#include<stdio.h>

#include "Common/Math.h"
#include "Common/Gaussian.h"
#include "Option/PayOff.h"

using namespace std;

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

    cout << (a == b) << endl;

    printf ("The complex number is (%f, %f) \n", d.re, d.im);
    printf ("The complex number is (%f, %f) \n", a.re, a.im);

    PayOffCall call_(1.20);

    cout << "The strike is" << 1.23 << endl;
    cout << "The pay off is " << call_(1.21) << endl;

    PayOffDoubleDigital test(1.50, 1.30);
    cout << "The pay off double digital is " << test(1.21) << endl;

    PayOffDoubleDigital test2(DigitalType::lowerLevel, 1.1);
    PayOff* test3 = test2.clone();

    cout << "The pay off digital(test2) is " << test2(1.01) << endl;
    cout << "The pay off digital(test3) is " << test3->operator()(1.01) << endl;

    cout << "Get gaussian is " << getOneGaussianByCLT()<< endl;
    
    return EXIT_SUCCESS;
}