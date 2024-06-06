#include <iostream>

//namespace Calculator
//{
//    int add(int x, int y) { return x + y; }
//    int sub(int x, int y) { return x - y; }
//    int mul(int x, int y) { return x * y; }
//    int div(int x, int y) { return x / y; }
//};

class IntCalculator
{
public:
    static int add(int x, int y) { return x + y; }
    static int sub(int x, int y) { return x - y; }
    static int mul(int x, int y) { return x * y; }
    static int div(int x, int y) { return x / y; }
};

class DoubleCalculator
{
public:
    static double add(double x, double y) { return x + y; }
    static double sub(double x, double y) { return x - y; }
    static double mul(double x, double y) { return x * y; }
    static double div(double x, double y) { return x / y; }
};

template <typename T>
class Calculator
{
public:
    static T add(T x, T y) {
        return x + y;
    }

    static T sub(T x, T y) { return x - y; }
    static T mul(T x, T y) { return x * y; }
    static T div(T x, T y) { return x / y; }
};

template <typename T, int Factor>
class AnotherCalculator
{
public:
    static T add(T x, T y) {
        return x + y;
    }

    static T mulByFactor(T x) {
        return x * Factor;
    }

    static T sub(T x, T y) { return x - y; }
    static T mul(T x, T y) { return x * y; }
    static T div(T x, T y) { return x / y; }
};

template <typename T, typename U, U Factor>
class YetAnotherCalculator
{
public:
    static T add(T x, T y) {
        return x + y;
    }

    static T mulByFactor(T x) {
        return x * Factor;
    }

    static T sub(T x, T y) { return x - y; }
    static T mul(T x, T y) { return x * y; }
    static T div(T x, T y) { return x / y; }
};

void test_templates()
{
    int result = Calculator<int>::add(1, 2);

    double dresult = Calculator<double>::add(1.3, 2.3);

    result = Calculator<int>::add(10, 22);

    // ==================================================

    result = AnotherCalculator<int, 10>::mulByFactor(5);
    result = AnotherCalculator<int, 20>::mulByFactor(5);
    result = AnotherCalculator<int, 30>::mulByFactor(5);

    // ==================================================

    long long llresult = YetAnotherCalculator<int, long long, 10ll>::mulByFactor(5);

    result = YetAnotherCalculator<int, short, 5>::mulByFactor(5);
}
