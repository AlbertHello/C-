//
//  main.cpp
//  day2
//
//  Created by 58 on 2019/4/20.
//  Copyright © 2019 58. All rights reserved.
//

#include <iostream>


//1、内联函数 （inline function）
//使用inline修饰函数的声明或者实现，可以使其变成内联函数，建议声明和实现都增加inline修饰
//特点：
//编译器会将函数调用直接展开为函数体代码
//可以减少函数调用的开销
//会增大代码体积
//注意
//尽量不要内联超过10行代码的函数
//有些函数即使声明为inline，也不一定会被编译器内联，比如递归函数





int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    
    return 0;
}
