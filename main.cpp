#include<iostream>
#include<stdio.h>

#include "Common/Math.h"

using namespace std;

int main()
{
    ComplexNumber a(1.0f, 2.0f);
    ComplexNumber b(2.0f, 3.0f);

    ComplexNumber c = a + b;

    printf ("The complex number is (%f, %f) \n", c.re, c.im);
    cout << (a==b) << endl;
    
    return EXIT_SUCCESS;
}