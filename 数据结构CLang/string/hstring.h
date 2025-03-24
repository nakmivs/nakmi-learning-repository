#ifndef STRING_H
#define STRING_H

#include "../common.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct HString{
    int length;
    char* ch; // 字符集选asicc，因为c中char就是一个字节，且是asicc字符集。
}HString;

// ------------ 基本操作的函数原型 -----------------

// 分配。 将常量字符串chars分配给str
Status StrAssign(HString* str, char* chars);
// 输出到标准输出
void PrintHString(HString* str){
    if (!str || !str->ch) {
        printf("(null)");
        return;
    }
    for (int i = 0; i < str->length; ++i) {
        putchar(str->ch[i]);
    }
}



Status StrAssign(HString* str, char* chars)
{
    // 首先是检查参数是否为NULL
    if(!str){
        printf("str为NULL");
        return ERROR;
    }
    if(!chars){
        free(str->ch);
        str->length = 0;
        return OK;
    }

    // 释放str
    if(!str->ch){
        free(str->ch);
        str->length = 0;
    }
    int chars_length = 0;
    for(char* c = chars; *c;++chars_length, c++); // 计算chars的长度，循环直到\0
    if(chars_length == 0){
        str->ch = NULL;
        str->length = 0;
    }else{
        if(!(str->ch = (char *)malloc(sizeof(char) * chars_length))) exit(OVERFLOW);
        
        // 复制字符串给str
        char* dest = str->ch;
        while(*dest++ = *chars++);
        // 设置str的长度
        str->length = chars_length;
    }
    return OK;
}

#endif