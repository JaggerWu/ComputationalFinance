#include<iostream>
#include<stdio.h>

#include "Common/Math.h"

using namespace std;

int main()
{
    ComplexNumber a(1.0f, 2.0f);
    ComplexNumber b(2.0f, 3.0f);

    ComplexNumber c = a + b;

    printf ("The complex number is (%f, %f)", c.re, c.im);

    return EXIT_SUCCESS;
}