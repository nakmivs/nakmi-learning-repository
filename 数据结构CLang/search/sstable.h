#ifndef SSTABLE_H
#define SSTABLE_H

#include "search.h"

// 顺序存储的 静态查找表
// 此处没有隐藏结构，是为了方便
typedef struct{
    SElemType* datas; // 数据数组
    int length; 
}SSTable; // 顺序存储的查询表

SSTable CreateSSTable(int n); // 创建具有n个数据元素的顺序表

void Traverse(SSTable sst);

// 顺序查找
int Search_Seq(SSTable sst, KeyType key);

// 折半查找 
int Search_Bin(SSTable sst, KeyType key);

#endif