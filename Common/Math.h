#ifndef MATH_H
#define MATH_H

#include <iostream>
#include <stdio.h>

class ComplexNumber
{
private:
    /* data */
public:
    double re, im;
    ComplexNumber();

    ComplexNumber(double a, double b): re(a), im(b) {}

    void Set(double _re, double _im);

    void operator+=(const ComplexNumber& cn);

    void operator-=(const ComplexNumber& cn);

    void operator*=(const double d);

    bool operator==(const ComplexNumber other);

    ComplexNumber& operator=(ComplexNumber& other);

    ~ComplexNumber();
};

inline ComplexNumber operator+(ComplexNumber& a, ComplexNumber& b)
{
    ComplexNumber c;
    c.im = a.im + b.im;
    c.re = a.re + b.re;

    return c;
}

inline ComplexNumber operator-(ComplexNumber& a, ComplexNumber& b)
{
    ComplexNumber c;
    c.im = a.im - b.im;
    c.re = a.re - b.re;

    return c;
}

inline ComplexNumber operator*(ComplexNumber& a, ComplexNumber& b)
{
    ComplexNumber c;
    c.re = a.re * b.re - a.im * b.im;
    c.im = a.re * b.im + a.im * b.re;

    return c;
}

inline ComplexNumber operator/(ComplexNumber& a, ComplexNumber& b)
{
    double base = a.im * a.im + b.im * b.im;
    ComplexNumber c;
    c.re = (a.re * b.re + a.im * b.im) / base;
    c.im = (- a.re * b.im + a.im * b.re) / base;

    return c;
}

#endif
