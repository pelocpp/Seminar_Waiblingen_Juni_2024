#include <stdio.h> // printf

extern int n;

void pointer_01()
{
    printf("Hallo pointer_01: %d\n", n);
}

void pointer_02()
{
    int n = 123;

    int* ip = NULL;

    ip = &n;    // Adresse bilden
                // eine Variable (n) 'referenzieren'

    *ip = 456;  // ohne den Bezeichner 'n' zu verwenden
                // indirekten Zugiff auf 'n'   
                // 'ip' 'dereferenzieren'     
                 
    n = 456;
}

void pointer_03()
{
    printf("sizeof (int): %zu\n", sizeof (int));
    printf("sizeof (long): %zu\n", sizeof(long));
    printf("sizeof (long long): %zu\n", sizeof(long long));
    printf("sizeof (short): %zu\n", sizeof(short));
    printf("sizeof (char): %zu\n", sizeof(char));

    int n = 123;

    int* ip = &n;

    printf("Value: %d\n", *ip);

    // Geht das ??????????????????????????

    printf("Value: %d\n", *ip);

    ip = ip + 1;

    printf("Value: %d\n", *ip);

    *ip = 456;

    printf("Value: %d\n", *ip);

    // =====================================

    char ch = '?';

    char* chp = &ch;

    chp++;
}

// =================================================

static void malZwei(int x)  // x ist formaler Parameter

                            // x : Platzhalter
{
    x = 2 * x;
}

void pointer_04()
{
    int n = 10;

    printf("n: %d\n", n);

    malZwei(n);             // aktueller Parmeter

    printf("n: %d\n", n);
}

// =================================================

static void malZweiEx(int* x)  // x ist formaler Parameter

{
    //x = 2 * x;

    int tmp = *x;

    tmp = 2 * tmp;

    *x = tmp;
}

void pointer_05()
{
    int n = 10;

    printf("n: %d\n", n);

    malZweiEx(&n);             // aktueller Parmeter

    printf("n: %d\n", n);
}

// =================================================
