#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void)
{
    int number;
    printf("Enter a decimal number to convert to binary: ");
    scanf("%d", &number);
    convertDecimalToBinary(number);
    return 0;
}