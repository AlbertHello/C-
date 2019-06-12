//
//  main.cpp
//  父类指针&子类指针
//
//  Created by 王启正 on 2019/6/11.
//  Copyright © 2019 58. All rights reserved.
//

#include <iostream>
using namespace std;

class Person {
public:
    int m_age;
};

class Student: public Person{
public:
    int m_score;
};

int main(int argc, const char * argv[]) {
    
    //父类指针可以指向子类对象,是安全的，开发中经常yoghurt到。继承方式必须是public
    Person *stu=new Student();
    stu->m_age=20;//父类指针仅能访问自己的成员变量，所以安全。
    
    
    // 子类指针指向父类对象不安全
    Student *p= (Student *) new Person();
    p->m_score=10;//new Person() 创建的父类对象只占四个字节，存储成员变量m_age的值。但子类指针指向了父类骗过了编译器，则能访问子类的m_score变量，但m_score并不存在于创建的new Person()父类对象中。所以不安全。
    
    cout << "Hello, World!\n";
    return 0;
}
