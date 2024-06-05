#include <iostream> // printf

int global = 1;

void test_dynamic_01()
{
    int n = 123;             // eine int Variable am STACK

    int* m = new int(123);   // eine int Variable auf dem HEAP

    // ...

    delete m;
}

void test_dynamic_02()
{
    int length = 10;
    // der Wert von length wird berechnet


    int* m = new int[length];

    // 2 OPTIONEN

    // A) mit Adress Arithmetik
    for (int i = 0; i < length; ++i) {
        *(m + i) = 2 * i;
    }

    // B) mit Index Schreibweise
    for (int i = 0; i < length; ++i) {
        m[i] = 2 * i;
    }

    // ...

    delete[] m;   // array delete !!!!!!!!!!
}

// Klassen

// kurze, nicht empfehlenswerte Schreibweise
class SimpleClass
{
private: 
    int m_n;

public:
    //chaining
    SimpleClass() : SimpleClass(0) {}

    SimpleClass(int n) : m_n(n) { std::cout << "c'tor" << std::endl; }

    ~SimpleClass() {

        // socket.close();
        std::cout << "d'tor" << std::endl;
    }

    void print() { std::cout << "print" << std::endl; }
};

void test_dynamic_03()
{
    SimpleClass scStack(123);

    SimpleClass* scHeap = new SimpleClass(123);

    delete scHeap;
}

void test_dynamic_04()
{
    SimpleClass objectsOnTheStack[5];   // STACK

    std::cout << "\n";

    SimpleClass* objectsOnTheHeap = new SimpleClass[3];

    std::cout << "\n";

    delete[] objectsOnTheHeap;

    std::cout << "\n";
}

void test_dynamic()
{
    test_dynamic_04();
}