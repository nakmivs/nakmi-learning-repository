#include <stdlib.h>
#include "sstable.h"

SSTable CreateSSTable(int n)
{
    if(n <= 0) exit(-1);
    SSTable sst;
    // 申请 n + 1 个空间， 是为了 0 号位用于
    sst.datas = malloc(sizeof(SElemType) * (n + 1));
    if(!sst.datas) exit(OVERFLOW);

    sst.length = n;
    int x;
    printf("please enter a sequence of %d numbers: ", n);
    for(int i=1; i <= n ; i++){
        scanf("%d ", &x);
        // key和data一样, 这是为了简化
        sst.datas[i].data = sst.datas[i].key = x;
    }

    return sst;
}

void Traverse(SSTable sst)
{
    for(int i=1; i <= sst.length; i++){
        printf("%d ", sst.datas[i].data);
    }
    printf("\n");
}

int Search_Seq(SSTable sst, KeyType key)
{
    // 顺序查找
    // 设置sst.data[0]为哨兵
    // 没有查询到返回0
    sst.datas[0].key = key;
    int i;
    for(i=sst.length;!EQ(sst.datas[i].key, key); i--);
    return i;
}

int Search_Bin(SSTable sst, KeyType key)
{
    // 折半查找
    // 适用于（1）顺序存储 （2）有序序列
    // 没有查询到 返回 0
    int low = 1, high=sst.length;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        /* code */
        if(EQ(sst.datas[mid].key, key)) {
            return mid;
        }else if(GT(sst.datas[mid].key, key)) {
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return 0; // 没有查询到 返回 0
}