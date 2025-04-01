#include <stdio.h>
#include "sstable.h"


void test_search(SSTable sst, int (* search_func)(SSTable sst, KeyType key))
{
    KeyType key;
    int result;
    while (1)
    {
        /* code */
        printf("enter the key: ");

        result = scanf("%d", &key);
        if (result != 1) { // 输入无效
            while (getchar() != '\n'); // 清空缓冲区
            printf("Invalid input. Please enter an integer.\n");
            continue;
        }


        int idx = search_func(sst, key);
        if(idx == 0){
            printf("Searching %d failure \n", key);
        }else{
            printf("Searching %d successful, locate at %d \n", key, idx);
        }
    }
}

int main()
{
    int len;
    printf("enter the number of data elements: ");
    scanf("%d", &len);
    SSTable sst = CreateSSTable(len);
    Traverse(sst);
    test_search(sst, Search_Seq);
    return 0;
}