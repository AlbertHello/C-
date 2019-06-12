//
//  main.cpp
//  多态
//
//  Created by 王启正 on 2019/6/11.
//  Copyright © 2019 58. All rights reserved.
//

#include <iostream>
using namespace std;

class Animal{
public:
    void run(){
        cout << "Animal:run()" <<endl;
    }
};


class Cat: public Animal{
public:
    void run(){
        cout << "Cat:run()" <<endl;
    }
};

class Dog: public Animal{
public:
    void run(){
        cout << "Dog:run()" <<endl;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
