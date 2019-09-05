#include <iostream>
#include <stdio.h>

#include "Math.h"

ComplexNumber::ComplexNumber()
{
    re = 0.0f;
    im = 0.0f;
}

void ComplexNumber::Set(double _re, double _im)
{
    re = _re;
    im = _im;
}

ComplexNumber::~ComplexNumber()
{
}

