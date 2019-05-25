//
//  main.cpp
//  析构函数
//
//  Created by 58 on 2019/5/25.
//  Copyright © 2019 58. All rights reserved.
//

#include <iostream>
using namespace std;


struct Car {//即便没有成员变量的类创建的时候也会占用一个字节
    int m_price;
    
    Car(){
        cout << "Car()" << endl;
    }
    ~Car(){
        cout << "~Car()" << endl;
    }
};


struct Person {
    int m_age;
//    Car m_car;
    Car *m_car_p;//m_car是个指针m_car_p的话，在释放person的时候并不会释放m_car_p指向的car对象，除非在析构函数中释放car
    //对对象创建完毕的时候调用
    Person(){
        cout << "Person()" << endl;
        this->m_age=0;
        this->m_car_p= new Car();//指针指向Car对象
    }
    //对象销毁的时候调用。内存回收。
    //析构函数(也叫析构器)，在对象销毁的时候自动调用，一般用于完成对象的清理工作
    ~Person(){
        //函数名以~开头，与类同名，无返回值(void都不能写)，无参，不可以重载，有且只有一个析构函数
        cout << "~Person()" << endl;
        
        delete this->m_car_p;//在这里释放m_car_p指向的car对象
    }
};
//注意
//通过malloc分配的对象free的时候不会调用构造函数
//构造函数、析构函数要声明为public，才能被外界正常使用


int main(int argc, const char * argv[]) {
   
    
    {
        //大括号是个具体的作用域，出了大括号，person就会被回收。
//        Person person;
    }
    
    Person *p=new Person();
    
    delete p;
    
    
    
    return 0;
}
