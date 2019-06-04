//
//  main.cpp
//  继承
//
//  Created by 王启正 on 2019/6/3.
//  Copyright © 2019 58. All rights reserved.
//

#include <iostream>
using namespace std;



//继承，可以让子类拥有父类的所有成员（变量或函数）
//struct Person {
//    int  m_age;
//    void run(){
//        cout <<"run()" <<endl;
//    }
//};
//
//struct Student:Person {
//    int  m_score;
//    void study(){
//        cout <<"study()" <<endl;
//    };
//};
//struct Worker:Person {
//    int  m_salary;
//    void work(){
//        cout <<"work()" <<endl;
//    };
//};


//struct Person {
//    int m_age;
//};
//
//struct Student : Person {
//    int m_no;
//};
//
//struct GoodStudent : Student {
//    int m_money;
//};

int myAge() {
    cout << "myAge()" << endl;
    return 30;
}

int myHeight() {
    cout << "myHeight()" << endl;
    return 180;
}



struct Person {
    int m_age;
    int m_height;

    //无参构造函数常用初始化方式 1
//    Person() {
//        this->m_age = 0;
//        this->m_height = 0;
//    }
    
    //无参构造函数初始化方式 2
    //构造函数之间的相互调用必须以初始化列表的方式调用，不能卸载函数体中
    Person():Person(10,10)/*这么写是正确的。*/{
        //这么写是错误的。直接调用构造函数会创建临时对象把临时对象的地址值传给了Person(10,10)函数中的this指针，并不是本函数中的this指针。
        //Person(10,10);//错误的。并不能赋值。
    }

    // 初始化列表 :m_age(age), m_height(height)
    //m_age(age)相当于this->m_age=age
    //m_height(height)相当于this->m_height=height
    // m_age(age),m_height(height)赋值有先后顺序，前面的先赋值，后面的后赋值
    Person(int age, int height) : m_age(age),m_height(height) {}//有参的构造函数初始化方式
    
    //初始化时调用外部函数都可以
//    Person(int age, int height) :m_height(myHeight()), m_age(myAge()) {}

    void display() {
        cout << "m_age is " << this->m_age << endl;
        cout << "m_height is " << this->m_height << endl;
    }
};


int main(int argc, const char * argv[]) {
    
    //继承
//    Student student;
//    student.m_age=20;
//    student.m_score=20;
//    student.run();//父类方法
//    student.study();
    
    
    //内存布局.父类的成员变量地址最小，排在最前面，gs的地址也就是第一个成员变量的地址，也就是m_age的地址。
//    GoodStudent gs;
//    gs.m_age = 20;
//    gs.m_no = 1;
//    gs.m_money = 2000;
//
//    cout << &gs << endl;
//    cout << &gs.m_age << endl;
//    cout << &gs.m_no << endl;
//    cout << &gs.m_money << endl;
    
    //初始化成员列表
//    Person person;
//    person.display();
//    cout << "-----------------" << endl;
//
//    Person person2(10, 20);
//    person2.display();
    
    //构造函数之间的调用
    Person person1;//默认调用无参的构造函数。
     person1.display();
    
    
    
    cout << "Hello, World!\n";
    return 0;
}
