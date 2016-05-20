//
//  main.cpp
//  LO21D3
//
//  Created by Hugo RODDE on 13/03/2014.
//  Copyright (c) 2014 Hugo RODDE. All rights reserved.
//

#include <iostream>
#include <string>
#include "fraction.h"

int main(int argc, const char * argv[])
{
    
    
    try {

        Math::Fraction troisquart(3,4);
        Math::Fraction cinqdemi(5,2);
        Math::Fraction zero(3,0);
        
        troisquart++;
        
        std::cout << troisquart;

    } catch (Math::FractionException const& e) {
        std::cerr << e.getInfos() << std::endl;
    }
    
    return 0;
}

