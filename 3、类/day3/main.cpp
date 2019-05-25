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
 类中的函数存放在内存中的代码区，所以类所占用的内存不包括函数的。
 this是指向当前对象的指针
 对象在调用成员函数的时候，会自动传入当前对象的内存地址赋值给this指针。
 
 */

class Person {
    //以class创建的类默认成员变量都是private的。
    int age;
    void run(){
        cout << "class Person run ()" << age << endl;
    }
    
};
struct anotherPerson {
    //以struct创建的类默认成员变量都是public的。
    int id;
    int age;
    int height;
    void run(){
        cout << "struct anotherPerson run ()" << age << endl;
    }
    void display(){
        
//        只有成员函数里才有this指针
        //类中的函数存放在内存中的代码区，所以类所占用的内存不包括函数的。
        //成员函数默认有个this参数，在调用函数的时候就默认把调用者的地址赋值给了this。
//        cout << "id is:" << id <<endl;
        cout << "id is:" << this->id <<endl;//正确写法
//        cout << "age is:" << age <<endl;
        cout << "age is:" << this->age <<endl;
//        cout << "height is:" << height <<endl;
        cout << "height is:" << this->height <<endl;
    }
};
int main(int argc, const char * argv[]) {
    
    
//    在栈空间分配了内存空间给person对象，这个person对象的内存会自动回收，不用管理。
//    Person person;//这样就相当于创建了类实例person
//    person.age=10;//以class创建的类,在类外部不能访问其成员变量。
    anotherPerson aPerson;
    //对象的内存布局：变量id的地址就是aPerson。
    aPerson.id=10;//对应的汇编代码：mov dword [ptr] [ebp-14h] 10
    aPerson.age=20;//对应的汇编代码：mov dword [ptr] [ebp-10h] 20
    aPerson.height=30;//对应的汇编代码：mov dword [ptr] [ebp-c0h] 30
    aPerson.display();//对应的汇编代码：call [028393920]
    
//    anotherPerson *p=&aPerson; //汇编代码lea ecx [ebp-14h]
    //通过指针访问anotherPerson对象
//    p->age=30;
//    p->run();
//  上面代码中person对象、p指针的内存都是在函数的栈空间，自动分配和回收的
    
    
    
    
    
    return 0;
}
