#ifndef PAYOFF_H
#define PAYOFF_H

enum OptionType
{
    call,
    put,
};

class PayOff
{
public:
    PayOff() {}
    virtual double operator()(double spot) const=0;
    virtual ~PayOff() {}
};

class PayOffCall: public PayOff
{
private:
    double strike;
    OptionType optionType = call;
public:
    PayOffCall(double Strike_);
    virtual double operator()(double Spot_) const;
    virtual ~PayOffCall() {}
};

class PayOffPut: public PayOff
{
private:
    double strike;
    OptionType optionType = put;
public:
    PayOffPut(double Strike_);
    virtual double operator()(double Spot_) const;
    virtual ~PayOffPut() {}
};

#endif