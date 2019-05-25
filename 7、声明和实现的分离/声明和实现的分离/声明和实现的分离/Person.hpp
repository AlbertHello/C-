//
//  Person.hpp
//  声明和实现的分离
//
//  Created by 58 on 2019/5/25.
//  Copyright © 2019 58. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
namespace Albert {
    //声明 放在头文件
    class Person{
        int m_age;
    public:
        Person();
        ~Person();
        void setAge(int age);
        int getAge();
    };
}


#endif /* Person_hpp */
