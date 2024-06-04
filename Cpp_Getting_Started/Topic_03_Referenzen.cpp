#include <iostream>

void test_references()
{
    // C

    int n = 123;

    int* ip;

    ip = &n;

    *ip = 456;

    // Adress Arithmetik
    ip++;

    *ip = *ip + 1;

    // ===================

    // C++

    int& ri = n;

    ri = 789;

    ri++;

    ri = ri + 1;

    n = n + 1;

    //  Adress Arithmetik mit Referenzen NICHT möglich
}

