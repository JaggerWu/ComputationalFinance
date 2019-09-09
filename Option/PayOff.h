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


enum DigitalType {
    lowerLevel,
    upperLevel,
};

class PayOffDigital: public PayOff
{
public:
    double level;
    DigitalType type;
private:
    PayOffDigital(DigitalType digitalType_, double level);
    virtual double operator()(double Spot_) const;
    virtual ~PayOffDigital() {}
};

class PayOffDoubleDigital: public PayOff
{
private:
    double upperLevel, lowerLevel;
public:
    PayOffDoubleDigital(double upperLevel_, double lowerLevel_);
    virtual double operator()(double Spot_) const;
    virtual ~PayOffDoubleDigital() {}
    
};

#endif