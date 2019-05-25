//
//  main.cpp
//  dya1
//
//  Created by Albert  on 2019/4/20.
//  Copyright © 2019 58. All rights reserved.
//

#include <iostream>
#include "one.h"

using namespace std;

//1、函数重载
//函数名相同，但参数个数不同、参数类型不同、参数顺序不同
//注意：
//返回值类型与函数重载无关
//调用函数时，实参的隐式类型转换可能产生二义性

//本质：
//采用了name mangling或者name decoration技术
//c++编译器默认会对符号名（变量名、函数名）进行改编、修饰。
//重载时会生成多个不同的函数名，不同的编译器（MSVC g++）有不同的生成的规则


//2、extern "C"
//由于C和C++编译规则的不同，在C、C++混合开发时，可能经常出现以下操作：
//C++ 调用C语言的API时，需要使用extern "C"修饰C语言的函数声明

//3、c++允许设置默认参数，在调用时可以根据情况省略实参，规则如下：
//默认参数只能按照右到左的顺序。比如func(int a=20)、func(int b, int c=3);
//如果函数同时有声明、实现，默认参数只能放在函数声明中。
//默认参数的值可以是常量、全局符号（全局变量、函数名）




//声明
void func();
void func(int);
void func(double, int);
void func(long, int);
void test();
void display(int, void(*funcPointer)() = test);//第二个参数是一个函数指针,默认指向test()函数


int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!" <<endl;
    
    //1、函数重载
    func();
    func(10);
    func(20.0, 4);
    //实参的隐式类型转换可能产生二义性
    //实参49可能会被隐式转换成double类型，也有可能是long类型.func(double, int)和func(long, int)都有可能会被调用，所以报错
//    func(49, 30);
    
    
     
    
    //2、extern "C". c++调用c函数
    int c=sum(10, 20);
    cout << c << endl;
    
    
    //3、默认参数
    display(10);
    
    return 0;
}
void func(){
    cout << "func()" <<endl;
}
void func(int c){
    cout << "func(int)" << c << endl;
}
void func(double a, int b){
    cout << "func(double, int)" << a+b << endl;
}
void func(long a, int b){
    cout << "func(long, int)" << a+b << endl;
}
//第二个参数是一个函数指针
void display(int a, void(*funcPointer)()){
    cout << "display(int, void(*funcPointer)())" << a << endl;
    cout << "funcPointer is" << funcPointer << endl;
    //调用指向的那个函数
    funcPointer();
}
void test(){
    cout << "test()" << endl;
}

