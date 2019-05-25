//
//  main.cpp
//  命名空间
//
//  Created by 58 on 2019/5/25.
//  Copyright © 2019 58. All rights reserved.
//

#include <iostream>
#include "Car.hpp"
#include "Person.hpp"

using namespace std;

void test(){
    cout << "test()"<< endl;
}


// 命名空间可以用来避免命名冲突
namespace A {
    int g_no;//这是个全局变量
    class Person{
    public:
        int m_age;
    };
    void test(){
        cout << "A::test()"<< endl;
    }
}
namespace B {
    int g_no;//这是个全局变量
    class Person{
    public:
        int m_height;
    };
    void test(){
        cout << "B::test()"<< endl;
    }
}

void testNameSpace(){
    {
        A::Person *person = new A::Person();
        person->m_age=20;
    }
    {
        B::Person person;
        person.m_height=30;
    }
    
    //俩全局变量互不干扰
    A::g_no=2;
    B::g_no=2;
    
    //三个全局函数的调用
    test();
    A::test();
    B::test();
}

//命名空间的嵌套
namespace C {
    namespace D {
        int g_no;
        class Person {
            
        };
    }
}


int main(int argc, const char * argv[]) {
    
    //命名空间的基本使用1
//    testNameSpace();
    
    //命名空间的基本使用2
//    using namespace A;//代表从这句代码后可直接使用A中的类、函数、变量等可以不加冒号
//    g_no=20;//直接使用.
//    Person person;
//    test();//二义性
    
    //命名空间的基本使用3
//    using A::g_no;//表明只是可以直接使用g_no变量，其他的仍需要带冒号。
//    g_no=30;
//    A::Person person;//仍需带冒号.
    
    
    //命名空间的嵌套使用
//    C::D::g_no=20;
//    using namespace C::D;
//    g_no=30;
    
    
    //有个默认的全局命名空间，我们创建的命名空间默认都嵌套在它里面.名字为空
    ::test();
    ::testNameSpace();//诸如此类用法
    
    //命名空间的合并
    //以下2种写法是等价的
    /**

     1、
     namespace E{
         int g_age;
     }
     namespace E{
         int g_no;
     }
     
     2、
     namespace E{
         int g_age;
         int g_no;
     }
     
     */
    //用法如下
    Albert::Person person;
    
    Albert::Car *car = new Albert::Car();
    delete car;
    
    
    
     return 0;
}
