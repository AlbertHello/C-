//
//  one.h
//  dya1
//
//  Created by 58 on 2019/4/20.
//  Copyright © 2019 58. All rights reserved.
//

#ifndef one_h //防止重复包含one.h文件
#define one_h

#include <stdio.h>

#ifdef __cplusplus //判断当前是C++环境，如果是就用extern "C" 表示此C文件可以给C++调用
extern "C"{
#endif
    
//    具体的C函数声明
    int sum(int,int);
    int minus(int,int);
    
    
#ifdef __cplusplus
}
#endif

#endif /* one_h */
