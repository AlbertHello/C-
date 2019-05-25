//
//  Car.cpp
//  命名空间
//
//  Created by 58 on 2019/5/25.
//  Copyright © 2019 58. All rights reserved.
//

#include "Car.hpp"
#include <iostream>
using namespace std;


namespace Albert{
    
    Car::Car(){
        cout << "Car()" << endl;
    }
    Car::~Car(){
        cout << "~Car()" << endl;
    }
}
