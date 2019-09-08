#include<iostream>
#include<stdio.h>

#include "Common/Math.h"
#include "Option/PayOff.h"

using namespace std;

int main()
{
    ComplexNumber a(1.0f, 2.0f);
    ComplexNumber b(2.0f, 3.0f);

    ComplexNumber c = a + b;

    printf ("The complex number is (%f, %f) \n", c.re, c.im);
    cout << (a==b) << endl;

    PayOffCall call_(1.20);

    cout << "The strike is" << 1.23 << endl;
    cout << "The pay off is " << call_(1.21) << endl;
    
    return EXIT_SUCCESS;
}