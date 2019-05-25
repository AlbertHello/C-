//
//  main.cpp
//  day4
//
//  Created by 58 on 2019/5/18.
//  Copyright © 2019 58. All rights reserved.
//

#include <iostream>
using namespace std;


//封装
class Person{
    
    int m_age;
    
public:
    Person(){
        //构造函数的函数名和类同名。无返回值，可以有参数，可以重载，可以有多个构造函数
        //一旦定义了构造函数就必须用构造函数初始化对象。
        //在对象创建时自动调用，一般用于对象的初始化操作。
        //默认情况下，只有在某些特定的情况下，编译器才会为类生成空的无参的构造函数
        this->m_age=0;//初始化
        cout << "构造函数" << endl;
    }
    Person(int age){
        //重载构造函数
        this->m_age=age;
        cout << "重载构造函数。age="<< age << endl;
    }
    void setAge(int age){
        if (age<0)return;
        this->m_age=age;
        cout << "age:" << this->m_age << endl;
    }
    int getAge(){
        return this->m_age;
    }
};

void test(){
    //堆空间申请：
    // new
    int *p=new int;
    *p=10;//把10存入p指向的地址。
    //释放
    delete p;
}

void test1(){
    //堆空间申请数组：
    // new
    int *p=new int[10];
    p[0]=10;
    p[1]=20;
    //释放
    delete[] p;
}
void  test2(){
    int *p1=new int; //未初始化,但Xcode好像默认给初始化了。仅在C++层面这句代码是没有初始化的
    int *p2=new int();//初始化为0
    int *p3=new int(5);//初始化为5
    int *p4=new int[3];//数组。也是未初始化的，Xcode帮忙初始化了。
    int *p5=new int[3]();//数组。全部初始化为0
    int *p6=new int[3]{};//数组。全部初始化为0
    int *p7=new int[3]{5};//数组。首元素初始化为5，其他初始化为0。
    
    cout << *p7 << endl;
    cout << *(p7+2) << endl;
}


//1、全局区
Person g_person1; //会调用默认的构造函数Person()。
Person g_person2();//注意，这是个函数声明。不会调用构造函数
Person g_person3(10);//会调用重载的构造函数Person(int age)

int main(int argc, const char * argv[]) {
    
    //封装。 用关键字class创建类，就体现了封装，因为默认变量和函数都是外部不可访问的。
//    Person person;
//    person.setAge(20);// 用setter和getter方法让外部间接访问成员变量，也是封装的概念。
//    cout << person.getAge() << endl;
    
    //堆的有关操作
//    test2();
    
    
//    Person person;//栈空间
//    Person *p=new Person();//堆空间
//    p->setAge(20);
//    delete p;//记得释放内存
    
    //构造函数
//    Person person();//默认调用第一个构造函数
    Person person(20);//或者使用new关键字:Person *p=new Person(20);默认调用第二个构造函数
    
    
    //2、栈空间
    Person person1;//会调用默认的构造函数Person()
    Person person2();//注意，这是个函数声明。不会调用构造函数
    Person person3(20);//会调用重载的构造函数Person(int age)
    
    
    //3、堆空间
    Person *p1=new Person;//会调用默认的构造函数Person()
    Person *p2=new Person();//会调用默认的构造函数Person()
    Person *p3=new Person(10);//会调用重载的构造函数Person(int age)
    
    
    
    
}
