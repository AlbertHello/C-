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
    //C++中的多态通过虚函数(virtual function)来实现
//    virtual void run(){
//        cout << "Animal:run()" <<endl;
//    }
    
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
//只要在父类中声明为虚函数，子类中重写的函数也自动变成虚函数(也就是说子类中可以省略virtual关键字)
//    void run(){
//        cout << "Dog:run()" <<endl;
//    }
    virtual void run(){
        cout << "Dog:run()" <<endl;
    }
};


class ErHa: public Dog{
public:
    void run(){
        cout << "ErHa:run()" <<endl;
    }
};

void liu(Animal *animal){
    animal->run();
}


int main(int argc, const char * argv[]) {
    
    
    // 虚函数关键字写在Animal中
//    Animal *animal0=new Cat();
//    Animal *animal1=new Dog();
//    Animal *animal2=new Animal();
//    animal0->run();
//    animal1->run();
//    animal2->run();
    
    //虚函数关键字写在Dog中。此时多台就不能完成。
//    Animal *animal1=new Animal();
//    Animal *animal2=new Dog();
//    Animal *animal3=new ErHa();
//    animal1->run();
//    animal2->run();
//    animal3->run();
    
    //virtual关键字写在Dog *dog1指针类型所在类中，多态才能起作用
    Dog *dog1=new Dog();
    Dog *dog2=new ErHa();
    dog1->run();
    dog2->run();
    
    
    
    
    
    
    return 0;
}
