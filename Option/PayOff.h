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
    virtual double operator()(double spot) const = 0;
    virtual ~PayOff() {}
    virtual PayOff* clone() const = 0;
};

class PayOffCall: public PayOff
{
private:
    double strike;
    OptionType optionType = OptionType::call;
public:
    PayOffCall(double Strike_);
    virtual double operator()(double Spot_) const;
    virtual ~PayOffCall() {}
    virtual PayOff* clone() const;
};

class PayOffPut: public PayOff
{
private:
    double strike;
    OptionType optionType = OptionType::put;
public:
    PayOffPut(double Strike_);
    virtual double operator()(double Spot_) const;
    virtual ~PayOffPut() {}
    virtual PayOff* clone() const;
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
    virtual PayOff* clone() const;
};

class PayOffDoubleDigital: public PayOff
{
private:
    double upperLevel, lowerLevel;
public:
    PayOffDoubleDigital(double upperLevel_, double lowerLevel_);
    virtual double operator()(double Spot_) const;
    virtual ~PayOffDoubleDigital() {}
    virtual PayOff* clone() const;
};

#endif