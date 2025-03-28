#include "hstring.h"

#include <stdio.h>

int main()
{
    HString s;
    StrAssign(&s, "hello");
    // printf("%c\n", );
    PrintHString(&s);
    printf("\n");
    return 0;
}