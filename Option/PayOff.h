#ifndef PAYOFF_H
#define PAYOFF_H

class PayOff
{
private:
    /* data */
public:
    virtual double operator()(double spot) const=0;
    PayOff(/* args */);

    virtual ~PayOff();
    virtual PayOff* clone() const=0;
};

PayOff::PayOff(/* args */)
{
}

PayOff::~PayOff()
{
}


#endif