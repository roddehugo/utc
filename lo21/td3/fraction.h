//
//  fraction.h
//  LO21D3
//
//  Created by Hugo RODDE on 13/03/2014.
//  Copyright (c) 2014 Hugo RODDE. All rights reserved.
//

#ifndef __LO21D3__fraction__
#define __LO21D3__fraction__

#include <iostream>
#include <string>

namespace Math
{

class FractionException
{

private:
    std::string info;
public:
    FractionException(const std::string& str):info(str) {};
    const std::string& getInfos() const
    {
        return info;
    };

};

class Fraction
{

public:
    Fraction();
    Fraction(int num, int den);

    int getNumerateur() const
    {
        return numerateur;
    };
    int getDenominateur() const
    {
        return denominateur;
    };
    void setFraction(int num, int den);
    int askDenominateur();

    Fraction operator++();
    Fraction operator++(int);

private:
    int numerateur;
    int denominateur;
    void simplification();
};

const Fraction operator+(const Fraction& f1, const Fraction& f2);
const Fraction operator+(const int entier, const Fraction& f2);

std::ostream& operator<<( std::ostream &flux, const Fraction& f);

}
#endif /* defined(__LO21D3__fraction__) */
