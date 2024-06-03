#include <stdio.h>

void typwandlung_01()
{
    printf("sizeof (short): %zu\n", sizeof (short));

    short n = 32767;

    printf("n: %d\n", n);

    n++;

    printf("n: %d\n", n);
}

void typwandlung_02()
{
    printf("sizeof (double): %zu\n", sizeof(double));
    printf("sizeof (float): %zu\n", sizeof(float));

    long long ll = 123l;
    int n = 456;

    long long llVar = 123ll;
    long l = (long) llVar;

    n = (int) ll;
    ll = n;

    double d = 123.5;
    float f = 456.5f;

    d = f;
    f = (float) d;
}

