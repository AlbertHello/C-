//
//  main.cpp
//  父类的构造函数
//
//  Created by 王启正 on 2019/6/11.
//  Copyright © 2019 58. All rights reserved.
//

#include <iostream>
using namespace std;

class Person {
    int m_age;
    
public:
//    Person(){
//        cout << "Person()" << endl;
//    }
//
    Person(int age) :m_age(age){
        cout << "Person()" << endl;
    }
    
};

class Student: public Person{
    int m_score;
public:
    //1、子类的构造函数默认会调用父类的无参构造函数
//    Student(){
//        cout << "Student()" << endl;
//    }
    
    //2、如果父类缺少无参构造函数，子类的构造函数必须显式调用父类的有参构造函数
    Student():Person(0){
        cout << "Student()" << endl;
    }
    //3、如果子类的构造函数显式地调用了父类的有参构造函数，就不会再去默认调用父类的无参构造函数
    //另外，构造函数调用构造函数只能写在初始化列表里
    Student(int age, int score) :m_score(score), Person(age){
        cout << "Student()" << endl;
    }
};


int main(int argc, const char * argv[]) {
    
    
    Student stu;
    
    
    cout << "Hello, World!\n";
    return 0;
}
