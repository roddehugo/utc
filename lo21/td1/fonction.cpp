//
//  fonction.cpp
//  LO21D1
//
//  Created by Hugo RODDE on 27/02/2014.
//  Copyright (c) 2014 Hugo RODDE. All rights reserved.
//

#include "fonction.h"
#include <iostream>
#include <string> 

using namespace std;

void exerciceA(){
    cout<<"donnez le rayon entier d’un cercle:";
    int r;
    cin>>r;
    double x=3.14;
    cout<<"\nx : "<<x;
    
    double y;
    y=3.14;
    cout<<"\ny : "<<y;
    double p, s;
    p=2*PI*r;
    s=PI*r*r;
    
    cout<<"\nle cercle de rayon "<<r;
    cout<<" a un perimetre de "<<p<<" et une surface de "<<s<<"\n";
}

void bonjour() {
    cout<<"Entrez votre prenom :";
    string prenom;
    cin>>prenom;
    cout<<"Bonjour "<<prenom<<"\n";
}