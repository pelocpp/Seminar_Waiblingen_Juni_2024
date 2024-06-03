#include <stdio.h>

extern void pointer_01();
extern void pointer_02();

// globale Variable
int n = 123;

int main()
{
    printf("Hallo Seminar\n");

    pointer_01();

    return 0;
}

