//
//  main.cpp
//  声明和实现的分离
//
//  Created by 58 on 2019/5/25.
//  Copyright © 2019 58. All rights reserved.
//

#include <iostream>
#include "Person.hpp"

using namespace std;



int main(int argc, const char * argv[]) {
    
    
    {
        Person person;
        person.setAge(20);
    }
    
    
    return 0;
}
