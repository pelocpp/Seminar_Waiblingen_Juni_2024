#include <iostream>

#include "DynamicIntArray.h"

#include "Time.h"

size_t computeLength()
{
    // komplexe Berechnung
    return 5;
}

void main_dynamic_int_array_01()
{
    size_t length = computeLength(); 

    DynamicIntArray numbers(length);

    // -------------------------------------------------
    // at

    int value = numbers.at(3);
    std::cout << "Value: " << value << std::endl;

    //numbers.at(5, 123);
    //value = numbers.at(5);
    //std::cout << "Value: " << value << std::endl;

    numbers.at(3) = 123;     // write
    value = numbers.at(3);   // read
    std::cout << "Value: " << value << std::endl;

    // -------------------------------------------------
    // operator[]

    numbers[1] = 123;
    value = numbers[1];

    // -------------------------------------------------
    // fill, print

    numbers.fill(123);
    numbers.print();

    // -------------------------------------------------
    // fill, print
    std::cout << numbers << '\n';

    //int x, y, z;
    //x = y = z = 3 + 4;

    // -------------------------------------------------
    // Objekt 'numbers' zu klein
}

void main_dynamic_int_array_02()
{
    DynamicIntArray numbers(10);

    numbers.fill(1);
    std::cout << numbers << "\n\n";

    numbers.resize(5);
    std::cout << numbers << "\n\n";

    numbers.resize(12);
    std::cout << numbers << "\n\n";
}

void main_dynamic_int_array()
{
    // Beobachtungen:

    int n = 123;
    int m = n;

    n = n;

    Time t(15, 38, 0);
    Time t2 = t;     // Kopier-Konstruktor
    t = t2;          // Wertzuweisung

    DynamicIntArray moreNumbers;
    DynamicIntArray numbers(10);
    DynamicIntArray copyOfNumbers = numbers; // Kopier-Konstruktor

    moreNumbers = numbers = copyOfNumbers;   // Wertzuweisung

    moreNumbers.fill(123);
    std::cout << moreNumbers << std::endl << std::endl;

    // Frage:
    moreNumbers = moreNumbers;
    std::cout << moreNumbers << std::endl;
}