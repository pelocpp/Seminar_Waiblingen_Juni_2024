// =======================================================

#include <stdio.h>
#include <stdlib.h>

extern void* my_malloc(size_t size)
{
    return NULL;
};

// C
void test_malloc()
{
    int* ip = (int*) my_malloc(sizeof(int));

    double* dp = (double*) my_malloc(sizeof(double));
}

// C++
void test_malloc_02()
{
    int* ip = new int(123);

    double* dp = new double(123);

    double* dp1 = dp;  // Kopie // Ownership

    delete ip;
    delete dp;
}