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
    
    
    
    //引用
    int age=10;
    //定义了一个引用，相当于age的别名
    int &rAge=age;//定义就得初始化，并且指向不能在改变
    //int &rAge1=rAge;//利用引用初始化另外一个引用，相当于age变量有多个别名
    rAge=40;//间接修改
    cout << rAge <<endl;
    cout << age <<endl;
    
    
    Season season;
    Season &rSeason=season;//枚举 引用
    rSeason=Winter;
    cout << season <<endl;
    
    
    Student stu;
    Student &rStu=stu;//结构体 引用
    rStu.age=10;
    cout << stu.age <<endl;
    
    int a=10;
    int b=20;
    int *p=&a;//指针p指向a的地址
    int *&rP=p; //相当于给指针p 添加了一个别名
    rP=&b;//现在又把指针p指向了b的地址
    *p=30;//重新给b赋值
    cout << a <<endl;
    cout << b <<endl;
    
    int array[]={10,20,30};
    int (&rArray)[3]=array;//数组 引用
    cout << rArray[0] <<endl;
    cout << rArray[1] <<endl;
    cout << rArray[2] <<endl;
    
    
    //修改函数返回值
    func()=30;//修改函数返回值
    cout << number <<endl;
    
    int v1=10;
    int v2=30;
    swap(v1, v2);
    cout << v1 <<endl;
    cout << v2 <<endl;
    
    return 0;
}
