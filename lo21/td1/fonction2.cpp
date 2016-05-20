//
//  fonction2.cpp
//  LO21D1
//
//  Created by Hugo RODDE on 27/02/2014.
//  Copyright (c) 2014 Hugo RODDE. All rights reserved.
//

#include "fonction2.h"

int fct(int x){
    std::cout<<"1:"<<x<<"\n";
    return 0;
}
int fct(float y){
    std::cout<<"2:"<<y<<"\n";
    return 0;
}
int fct(int x, float y){
    std::cout<<"3:"<<x<<y<<"\n";
    return 0;
}
float fct(float x, int y){
    std::cout<<"4:"<<x<<y<<"\n";
    return 3.14;
}

void exercice_surcharge(){
    int i=3,j=15;
    float x=3.14159, y=1.414;
    char c='A';
    double z=3.14159265;
    
    fct(i);
    //appel 1
    fct(x);
    //appel 2
    fct(i,y);
    //appel 3
    fct(x,j);
    //appel 4
    fct(c);
    //appel 5
    fct(i,static_cast<float>(j));
    //appel 6
    //fct(i,c);
    //appel 7
    //fct(i,z);
    //appel 8
    //fct(z,z);
    //appel 9
}
