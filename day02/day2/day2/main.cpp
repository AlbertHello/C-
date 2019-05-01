//
//  main.cpp
//  day2
//
//  Created by 58 on 2019/4/20.
//  Copyright © 2019 58. All rights reserved.
//

#include <iostream>
using namespace std;


/**
 1、内联函数 （inline function）
 
 使用inline修饰函数的声明或者实现，可以使其变成内联函数，建议声明和实现都增加inline修饰
 特点：
 编译器会将函数调用直接展开为函数体代码
 可以减少函数调用的开销
 会增大代码体积
 注意：
 尽量不要内联超过10行代码的函数
 有些函数即使声明为inline，也不一定会被编译器内联，比如递归函数
 函数代码量不是很多，且调用频率比较高时可选用内联函数
 内联函数和宏：
 内联函数和宏都可减少函数调用的内存开销，但是内联函数比宏多了语法检测
 
 ◼ 我们经常使用#ifndef、#define、#endif来防止头文件的内容被重复包含
 ◼#pragma once可以防止整个文件的内容被重复包含
 ◼区别
 #ifndef、#define、#endif受C\C++标准的支持，不受编译器的任何限制
 有些编译器不支持#pragma once(较老编译器不支持，如GCC 3.4版本之前)，兼容性不够好
 #ifndef、#define、#endif可以针对一个文件中的部分代码，而#pragma once只能针对整个文件
 
 */


/**
 2、引用(Reference)
 
 ◼ 在C语言中，使用指针(Pointer)可以间接获取、修改某个变量的值
 ◼ 在C++中，使用引用(Reference)可以起到跟指针类似的功能
 ◼ 注意点
    引用相当于是变量的别名(基本数据类型、枚举、结构体、类、指针、数组等，都可以有引用)
    对引用做计算，就是对引用所指向的变量做计算
    在定义的时候就必须初始化，一旦指向了某个变量，就不可以再改变，“从一而终”
    可以利用引用初始化另一个引用，相当于某个变量的多个别名
    不存在【引用的引用、指向引用的指针、引用数组】
 
 ◼ 引用存在的价值之一:比指针更安全、函数返回值可以被赋值
 ◼ 引用的本质就是指针，只是编译器削弱了它的功能，所以引用就是弱化了的指针
 ◼ 一个引用占用一个指针的大小
 */

/**
 3、const是常量的意思，被其修饰的变量不可更改
    如果修饰的是类、结构体（的指针），其成员也不可以被更改
 
    以下5个指针分别是什么含义？
 int age=10;
 const int *p0=&age;  *p0是常量(age的值不可改变)，p0不是常量（p0可以再指向其他变量）
 int const *p1=&age;  *p1是常量(age的值不可改变)，p1不是常量（p0可以再指向其他变量）
 int * const p2=&age;  p2是常量(p2不可以再指向其他变量），*p2不是常量(age的值可改变)
 const int * const p3=&age; p3是常量(p3不可以再指向其他变量），*p3是常量(age的值不可改变)
 int const * const p4=&age; p4是常量(p4不可以再指向其他变量），*p4是常量(age的值不可改变)
 以上指针的问题可以用以下结论来解决：
 const 修饰的是其右边的内容
 
 ◼ const引用的特点
 可以指向临时数据(常量、表达式、函数返回值等)
 可以指向不同类型的数据
 作为函数参数时(此规则也适用于const指针)
 ✓ 可以接受const和非const实参(非const引用，只能接受非const实参)
 ✓ 可以跟非const引用构成重载
 
 
 ◼ 当常引用指向了不同类型的数据时，会产生临时变量，即引用指向的并不是初始化时的那个变量
 
 */

/**
 4、 汇编
 ◼ 汇编语言的种类
 8086汇编(16bit)
 x86汇编(32bit)
 x64汇编(64bit)
 ARM汇编(嵌入式、移动设备)
 ......
 ◼ x64汇编根据编译器的不同，有2种书写格式
 Intel
 AT&T
 ◼ 汇编语言不区分大小写
 
 x64汇编要点总结：
 ◼mov dest, src
 将src的内容赋值给dest，类似于dest = src
 ◼[ 地址值 ]
 中括号[ ]里面放的都是内存地址
 ◼word是2字节，dword是4字节(double word)，qword是8字节(quad word)
 ◼call 函数地址
 调用函数
 ◼lea dest, [ 地址值 ]
 将地址值赋值给dest，类似于dest = 地址值
 ◼ret
 函数返回
 ◼xor op1, op2
 将op1和op2异或的结果赋值给op1，类似于op1 = op1 ^ op2
 ◼add op1, op2
 类似于op1 = op1 + op2
 ◼sub op1, op2
 类似于op1 = op1 - op2
 inc op
 自增，类似于op = op + 1
 ◼dec op
 自减，类似于op = op – 1
 ◼jmp 内存地址
 跳转到某个内存地址去执行代码 j开头的一般都是跳转，大多数是带条件的跳转，一般跟test、cmp等指令配合使用
 ◼ 权威参考:Intel白皮书
 https://software.intel.com/en-us/articles/intel-sdm
 ◼ 一个变量的地址值，是它所有字节地址中的最小的那个地址值

 */



//内联函数
inline int sum(int a, int b){
    return a+b;
}

enum Season{
    Spring,
    Summer,
    Fall,
    Winter
};

struct Student {
    int age;
    char *name;
};

int number=20;//全局变量
//函数返回一个引用
int &func(){
    //。。。。 假设函数进行了对全局变量的操作。。
    return number;
}

//利用引用来交换两个值。比C语言中写法要简略
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
//C语言中交换两个值的写法
void swap_c(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << sum(10,20)<<endl; //调用内联函数，直接替换函数体代码：cout << 10+20 <<endl;
    
    
    
//    //引用
//    int age=10;
//    //定义了一个引用，相当于age的别名
//    int &rAge=age;//定义就得初始化，并且指向不能在改变
//    //int &rAge1=rAge;//利用引用初始化另外一个引用，相当于age变量有多个别名
//    rAge=40;//间接修改
//    cout << rAge <<endl;
//    cout << age <<endl;
//
//
//    Season season;
//    Season &rSeason=season;//枚举 引用
//    rSeason=Winter;
//    cout << season <<endl;
//
//
//    Student stu;
//    Student &rStu=stu;//结构体 引用
//    rStu.age=10;
//    cout << stu.age <<endl;
//
//    int a=10;
//    int b=20;
//    int *p=&a;//指针p指向a的地址
//    int *&rP=p; //相当于给指针p 添加了一个别名
//    rP=&b;//现在又把指针p指向了b的地址
//    *p=30;//重新给b赋值
//    cout << a <<endl;
//    cout << b <<endl;
//
//    int array[]={10,20,30};
//    int (&rArray)[3]=array;//数组 引用
//    cout << rArray[0] <<endl;
//    cout << rArray[1] <<endl;
//    cout << rArray[2] <<endl;
//
//
//    //修改函数返回值
//    func()=30;//修改函数返回值
//    cout << number <<endl;
//
//    int v1=10;
//    int v2=30;
//    swap(v1, v2);
//    cout << v1 <<endl;
//    cout << v2 <<endl;
    
    
    int age=10;
    //*p1是常量(age的值不可改变)，p1不是常量（p1可以再指向其他变量）
    int const *p1=&age;
    // p2是常量(p2不可以再指向其他变量），*p2不是常量(age的值可改变)
    int * const p2=&age;
    
    //常引用
    //引用的本质就是指针
//    int & const rAge1=age; //这样写报错。
    //不能通过引用修改所指向的内容
    int const &rAge2=age; //const必须写在&符号的左边，才能算是常引用。表示此时age的值不能被改变了。所以下面的代码会报错
//    rAge2=3;//这样写报错
    
    
    return 0;
}
