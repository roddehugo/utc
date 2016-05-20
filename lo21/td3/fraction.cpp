//
//  fraction.cpp
//  LO21D3
//
//  Created by Hugo RODDE on 13/03/2014.
//  Copyright (c) 2014 Hugo RODDE. All rights reserved.
//

#include "fraction.h"

using namespace Math;

Fraction::Fraction(){
    int num, den;
    std::cout << "Entrer le numérateur : ";
    std::cin >> num;
    
    den = Fraction::askDenominateur();
    Fraction::setFraction(num, den);
}

Fraction::Fraction(int num, int den){
    //if (den==0) {
    //  std::cout << "Denominateur nul ! Interdit !";
    //  den = Fraction::askDenominateur();
    //}
    Fraction::setFraction(num, den);
}

void Fraction::setFraction(int num, int den){
    if(den==0)
        throw Math::FractionException("Exception : Division par zéro imossible");
    denominateur = den;
    numerateur = num;
    simplification();
}

int Fraction::askDenominateur(){
    // demande un dénominateur à l'utilisateur tant que celui-ci est égal à 0
    int den = 0;
   // while (den == 0) {
     //   std::cout << "Entrer le dénominateur (différent de 0) : ";
       /// std::cin >> den;
    //}
    return den;
}

void Fraction::simplification(){
    // si le numerateur est 0, le denominateur prend la valeur 1
    if (numerateur==0) { denominateur=1; return; }
    /* un denominateur ne devrait pas être 0;
     si c’est le cas, on sort de la méthode */
    if (denominateur==0) return;
    /* utilisation de l’algorithme d’Euclide pour trouver le Plus Grand Commun
     Denominateur (PGCD) entre le numerateur et le denominateur */
    int a=numerateur, b=denominateur;
    // on ne travaille qu’avec des valeurs positives...
    if (a<0) a=-a; if (b<0) b=-b;
    while(a!=b){ if (a>b) a=a-b; else b=b-a; }
    // on divise le numerateur et le denominateur par le PGCD=a
    numerateur/=a; denominateur/=a;
    // si le denominateur est négatif, on fait passer le signe - au denominateur
    if (denominateur<0) { denominateur=-denominateur; numerateur=-numerateur; }
}

// prefix
Fraction Fraction::operator++(){
    return (*this=1 + *this);
}

// postfix
Fraction Fraction::operator++(int){
    return (*this=1 + *this);
}

// en dehors de la classe

const Fraction Math::operator+(const Fraction& f1, const Fraction& f2){
    return Fraction(f1.Fraction::getDenominateur()*f2.getNumerateur() + f1.getNumerateur()*f2.getDenominateur(), f1.getDenominateur()*f2.getDenominateur());
}

const Fraction Math::operator+(const int entier, const Fraction& f){
    return Fraction(entier*f.getDenominateur()+f.getNumerateur(), f.getDenominateur());
}

std::ostream& Math::operator<<( std::ostream &flux, const Fraction& f){
    flux << f.getNumerateur() << "/" << f.getDenominateur() << "\n";
    return flux;
}
