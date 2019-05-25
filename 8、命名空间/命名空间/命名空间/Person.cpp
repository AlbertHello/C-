//
//  Person.cpp
//  声明和实现的分离
//
//  Created by 58 on 2019/5/25.
//  Copyright © 2019 58. All rights reserved.
//

#include "Person.hpp"
#include <iostream>
using namespace std;
namespace Albert {
    //实现 放在.cpp文件中
    //:: 域运算符，指明所属关系
    Person::Person(){
        cout << "Person()" << endl;
    }
    Person::~Person(){
        cout << "~Person()" << endl;
    }
    void Person::setAge(int age){
        this->m_age=age;
        cout << "m_age" << this->m_age << endl;
    }
    int Person::getAge(){
        
        return this->m_age;
    }
}
