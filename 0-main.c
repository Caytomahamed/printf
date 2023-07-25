#include "main.h"
#include <stdio.h>

int main(void)
{
    int len;

    len = _printf("cs%", 'B', "Cayto");
    printf("%d\n", len);
    return (0);
}
