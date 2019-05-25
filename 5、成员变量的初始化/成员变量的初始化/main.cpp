//
//  main.cpp
//  成员变量的初始化
//
//  Created by 58 on 2019/5/25.
//  Copyright © 2019 58. All rights reserved.
//

#include <iostream>
using namespace std;

//研究成员变量初始化所用
struct Person {
    int m_age;
    
};


//1、全局区 （成员变量初始化为0）
Person g_person; //会调用默认的构造函数Person()。

int main(int argc, const char * argv[]) {
    
    
    //2、栈空间 (成员变量没有初始化)
    Person person;//会调用默认的构造函数Person()
    
    //3、堆空间
    Person *p1=new Person;//成员变量没有初始化
    Person *p2=new Person();//成员变量初始化为0
    
    
    //成员变量的初始化
    cout << "g_person " << g_person.m_age <<endl;//0
    cout << "person " << person.m_age <<endl;//-272632560
    cout << "p1 " << p1->m_age <<endl;//0 虽然打印出0但这是Xcode编译器优化了代码，帮助初始化
    cout << "p2 " << p2->m_age <<endl;//0
    
    
    //注意：
    // 如果自定义了构造函数，除了全局区，其他内存空间的成员变量默认都不会被初始化，需要开发人员手动初始化
    
    
    return 0;
}
