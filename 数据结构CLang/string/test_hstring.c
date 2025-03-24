#include "hstring.h"

#include <stdio.h>

int main()
{
    HString s;
    StrAssign(&s, "helloworld");
    // printf("%c\n", );
    PrintHString(&s);
    return 0;
}