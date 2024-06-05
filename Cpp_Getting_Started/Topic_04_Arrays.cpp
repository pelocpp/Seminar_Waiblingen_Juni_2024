#include <iostream> // printf

void test_arrays_01()
{
    // int numbers1[10];

    int numbers2[10] = { 1, 2, 3 };

    int numbers3[10] = { 0 };

    int numbers4[] = { 1, 2, 3, 4, 5 };
}

void test_arrays_02()
{
    int numbers1[1000000] = {};
}

// No-Go
void printArray_01(int feld[10])
{
    for (int i = 0; i < 10; ++i) {
        std::cout << i << ": " << feld[i] << '\n';
    }
}

void printArray_02(int feld[], int len)
{
    for (int i = 0; i < len; ++i) {
        std::cout << i << ": " << feld[i] << '\n';
    }
}

void printArray_03(int* feld, int len)
{
    for (int i = 0; i < len; ++i) {
        std::cout << i << ": " << feld[i] << '\n';
    }
}

void printArray_04(int* feld, int len)
{
    for (int i = 0; i < len; ++i) {
        std::cout << i << ": " << *(feld + i) << '\n';
    }
}

void test_arrays_04()
{
    const int n = 5;

    int numbers[n] = { 0 };  // FIXED-SIZE

    printArray_03(numbers, sizeof(numbers) / sizeof(int));
}

// Spielerei :-)
void test_arrays_05()
{
    int numbers[5] = { 1, 2, 3, 4, 5 };

    int value = numbers[3];

    value = *(numbers + 2);

    value = *(2 + numbers);

    value = 2[numbers];

    value = numbers[-100];

    // printf "  %d  "
}