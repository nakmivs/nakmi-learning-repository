#ifndef SEARCH_H
#define SEARCH_H

#include "../common.h"

typedef int KeyType; // 整型关键字
typedef struct {
    ElemType data; // 数据元素
    KeyType key;  // 关键字
}SElemType; // 

#define EQ(a, b) ((a) == (b))
#define LT(a, b) ((a) < (b))
#define LQ(a, b) ((a) <= (b))
#define GT(a, b) ((a) > (b))
#define GQ(a, b) ((a) >= (b))

#endif