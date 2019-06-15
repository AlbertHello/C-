//
//  main.cpp
//  虚析构函数
//
//  Created by 58 on 2019/6/15.
//  Copyright © 2019 58. All rights reserved.
//

#include <iostream>
using namespace std;

class Animal {
public:
    int m_age;
    //子类的构造函数默认会调用父类的无参构造函数
    Animal() :m_age(0) {
        cout << "Animal()" <<endl;
    }
    virtual void speak() {
        cout << "Animal::speak()" << endl;
    }
    virtual void run() {
        cout << "Animal::run()" << endl;
    }
//    含有虚函数的类，应该将析构函数声明为虚函数(虚析构函数),如果不写virtual，并且是用父类指针指向子类创建的对象，类似于：Animal *cat1 = new Cat(); 那么此时delete cat1时，只有父类能析构，子类不能析构
     virtual ~Animal() {
        cout << "~Animal()" << endl;
    }
};

class Cat : public Animal {
public:
    int m_life;
    Cat() :m_life(0) {
        cout << "Cat()" <<endl;
    }
    void speak() {
        cout << "Cat::speak()" << endl;
    }
    void run() {
        cout << "Cat::run()" << endl;
    }
    ~Cat() {
        cout << "~Cat()" << endl;
    }
};


int main() {
    Animal *cat1 = new Cat();
    cat1->speak();
    cat1->run();

    delete cat1;
    
    return 0;
}
