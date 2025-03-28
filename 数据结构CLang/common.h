#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>

// 函数结果状态码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

// Status是函数的类型，值是函数结果状态码
typedef int Status;

typedef int Bool;

// 一般的数据元素的类型
typedef int ElemType;

#endif