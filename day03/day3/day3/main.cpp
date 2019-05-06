//
//  main.cpp
//  day3
//
//  Created by 王启正 on 2019/5/6.
//  Copyright © 2019 58. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 面向对象---类
 C++中可以使用struct、class来定义一个类
 struct和class的区别：
 struct的默认成员权限是public
 class的默认成员权限是private
 
 */


int main(int argc, const char * argv[]) {
    
    
    
    class Person {
      //以class创建的类默认成员变量都是private的。
        int age;
        void run(){
            cout << "class Person run ()" << age << endl;
        }
        
    };
    struct anotherPerson {
        //以struct创建的类默认成员变量都是public的。
        int age;
        void run(){
            cout << "struct anotherPerson run ()" << age << endl;
        }
    };
    
//    Person person;//这样就相当于创建了类实例person
//    person.age=10;//以class创建的类,在类外部不能访问其成员变量。
    
    anotherPerson aPerson;
//    aPerson.age=20;
//    aPerson.run();
    
    anotherPerson *p=&aPerson;
    p->age=30;//通过指针访问anotherPerson对象
    p->run();
//  上面代码中person对象、p指针的内存都是在函数的栈空间，自动分配和回收的
    
    
    
    return 0;
}
