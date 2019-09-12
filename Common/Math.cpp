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

void ComplexNumber::operator+=(const ComplexNumber& cn)
{
    re += cn.re;
    im += cn.im;
}

void ComplexNumber::operator-=(const ComplexNumber& cn)
{
    re -= cn.re;
    im -= cn.re;
}

void ComplexNumber::operator*=(const double d)
{
    re *= d;
    im *= d;
}

bool ComplexNumber::operator==(const ComplexNumber other)
{
    if (re == other.re && im == other.im)
    {
        return true;
    }
    return false;
}

ComplexNumber& ComplexNumber::operator=(ComplexNumber& other)
{
    if (this != &other)
    {
        re = other.re;
        im = other.im;
    }
    
    return *this;
}

ComplexNumber& ComplexNumber::operator+(ComplexNumber& other)
{
    ComplexNumber* ptr = new ComplexNumber(other.re + re, other.im + im);
    
    return (*ptr);
} 

ComplexNumber& ComplexNumber::operator-(ComplexNumber& other)
{
    ComplexNumber* ptr = new ComplexNumber(re - other.re, im - other.im);
    
    return (*ptr);
} 
