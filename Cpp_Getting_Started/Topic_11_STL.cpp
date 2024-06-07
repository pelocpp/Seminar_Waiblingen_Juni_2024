#include <iostream>
#include <vector>
#include <algorithm>

void test_stl_01()
{
    std::vector<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    for (int i = 0; i < numbers.size(); ++i)
    {
        std::cout << i << ": " << numbers[i] << '\n';
    }
}

void test_stl_02()
{
    std::vector<int> numbers;

    for (int i = 0; i < 100; ++i)
    {
        numbers.push_back(2 * i);

        std::cout
            << i << ": " << numbers.size() 
            << " - Capacity: " << numbers.capacity() 
            << '\n';
    }
}

void test_stl_03()
{
    std::vector<int> numbers;

    numbers.reserve(90);

    // Verarnbeitung
    for (int i = 0; i < 100; ++i)
    {
        numbers.push_back(2 * i);

        std::cout
            << i << ": " << numbers.size()
            << " - Capacity: " << numbers.capacity()
            << '\n';
    }

    numbers.shrink_to_fit();

    std::cout
        << numbers.size()
        << " - Capacity: " << numbers.capacity()
        << '\n';
}

void test_stl_05()
{
    using MyContainer = std::vector<int>;

    // typedef std::vector<int> MyContainer2;

    MyContainer numbers;
}


void test_stl_06()
{
    std::vector<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    std::vector<int>::iterator pos = numbers.begin();
    if (pos == numbers.end()) {
        std::cout << "Ende des Containers!\n";
        return;
    }

    int value = *pos;
    std::cout << "Value: " << value << '\n';

    ++pos;
    if (pos == numbers.end()) {
        std::cout << "Ende des Containers!\n";
        return;
    }
    value = *pos;
    std::cout << "Value: " << value << '\n';

    ++pos;
    if (pos == numbers.end()) {
        std::cout << "Ende des Containers!\n";
        return;
    }
    value = *pos;
    std::cout << "Value: " << value << '\n';

    ++pos;
    if (pos == numbers.end()) {
        std::cout << "Ende des Containers!\n";
        return;
    }
    value = *pos;
    std::cout << "Value: " << value << '\n';
}

void test_stl_07()
{
    std::vector<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    std::vector<int>::iterator pos = numbers.begin();
    std::vector<int>::iterator end = numbers.end();

    for (; pos != end; ++pos) {

        std::cout << "Value: " << *pos << '\n';
    }

    std::cout << "Ende des Containers!\n";
}

void print(int value)
{
    std::cout << "Value: " << value << '\n';
}

void print1(int& value)
{
    std::cout << "Value&: " << value << '\n';
}

void print2(int& value)
{
    value = 2 * value;
    std::cout << "Value&: " << value << '\n';
}


void test_stl_08()
{
    std::cout << "test_stl_08:\n";

    std::vector<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    std::for_each(
        numbers.begin(),
        numbers.end(),
        print
    );

    std::cout << "Ende des Containers!\n";
}

void test_stl_09()
{
    std::cout << "test_stl_09:\n";

    std::vector<int> numbers (20);

    std::for_each(
        numbers.begin(),
        numbers.end(),
        print
    );

    std::cout << "\n";

    for (int i = 0; i < numbers.size(); ++i)
    {
        numbers[i] = 2 * i;
    }

    std::for_each(
        numbers.begin(),
        numbers.end(),
        print
    );

    // versus

    std::fill(
        numbers.begin(),
        numbers.end(),
        2
    );

    std::for_each(
        numbers.begin(),
        numbers.end(),
        print
    );

    // Spielerei
    int* start = numbers.data();
    std::memset(start, '1', sizeof (int) * 20);

    std::for_each(
        numbers.begin(),
        numbers.end(),
        print
    );

    std::cout << "Ende des Containers!\n";
}

void set(int& value)
{
    static int i = 0;

    ++i;

    value = 2 * i;
}

void test_stl_10()
{
    std::cout << "test_stl_10:\n";

    std::vector<int> numbers(10);

    std::for_each(
        numbers.begin(),
        numbers.end(),
        print
    );

    std::for_each(
        numbers.begin(),
        numbers.end(),
        set
    );

    std::for_each(
        numbers.begin(),
        numbers.end(),
        print
    );

    std::cout << "Ende des Containers!\n";
}

class ValueProvider
{
private:
    mutable int m_value;
    // std::mutex

public:

    ValueProvider () : m_value(0) {}

    ValueProvider(int start) : m_value(start) {}

    int getNextValue() {
        ++m_value;
        return m_value;
    }

    int operator () () const {
        ++m_value;
        return m_value;
    }

    int operator () (int offset) {
        m_value = m_value + offset;
        return m_value;
    }
};

void test_stl_11()
{
    ValueProvider provider(5);

    //int n = provider.getNextValue();
    //std::cout << n << std::endl;

    //n = provider.getNextValue();
    //std::cout << n << std::endl;

    //n = provider.getNextValue();
    //std::cout << n << std::endl;

    int n = provider(5);
    std::cout << n << std::endl;

    n = provider(5);
    std::cout << n << std::endl;

    n = provider(5);
    std::cout << n << std::endl;
}

void test_stl_12()
{
    std::cout << "test_stl_12:\n";

    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    std::for_each(
        numbers.begin(),
        numbers.end(),
        print2
    );

    std::cout << "Ende des Containers!\n";
}


int erzeugeWert()
{
    return 123;
}

void test_stl_13()
{
    std::cout << "test_stl_12:\n";

    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    std::generate(
        numbers.begin(),
        numbers.end(),
        erzeugeWert
    );

    std::cout << "Ende des Containers!\n";
}

int setDieZweite()
{
    static int i = 50;

    ++i;

    int value = 2 * i;

    return value;
}


void test_stl_14()
{
    std::cout << "test_stl_12:\n";

    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    ValueProvider provider(10);  // Konstruktor

    std::generate(
        numbers.begin(),
        numbers.end(),
        // provider               // operator ()
        setDieZweite
    );

    std::cout << "Ende des Containers!\n";
}

void test_stl()
{
    test_stl_14();
}
