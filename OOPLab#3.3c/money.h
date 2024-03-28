#pragma once
#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <sstream>

class Money {
private:
    long hryvnia; 
    unsigned char kopiyka; 

public:
    Money();
    Money(long h, unsigned char k);
    Money(const Money& other);

    void Init(long h, unsigned char k);
    void Read();
    void Display();
    std::string toString();

    Money operator+(const Money& other) const;
    Money operator/(int divisor) const;
    Money operator/(double divisor) const;

    Money& operator=(const Money& other);
    Money& operator++();
    Money operator++(int);
    Money& operator--();
    Money operator--(int);


    friend std::istream& operator>>(std::istream& in, Money& money);
    friend std::ostream& operator<<(std::ostream& out, const Money& money);
};

#endif 
