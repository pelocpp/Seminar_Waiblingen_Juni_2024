#include <iostream>

//void test_auto()
//{
//    var o;
//    let o2;
//
//    auto x;
//
//    o.wert = 123;
//}

void test_auto_01()
{
    auto x = (short) 123;  // Typ Ableitung

    // sequence statement
    123, 123l, 123ll, 123.123,
    'A', "DASAD", (short)456;

    auto value = 123;
}


long berechneWert() {
    return 0l;
}

void test_auto_02()
{
    auto x = (short)123;  // Typ Ableitung

    // sequence statement
    123, 123l, 123ll, 123.123,
        'A', "DASAD", (short)456;

    auto value = 123;

    auto anotherValue = berechneWert();
}

class Contact
{
private:
    size_t m_number;
    std::string m_name;

    // ...
public:
    // getter
    auto getNumber() { return m_number; }
    auto getName() { return m_name; }
};

// ======================================


long long calculateValue()
{
    return 0l;
}

auto calculateValueEx() -> long long
{
    return 0l;
}

template <typename T, typename U>
auto calculateValueExEx(T t, U u) -> decltype (t+u)
{
    // ....
    return t+u;
}

void main_calculateValueEx()
{
    auto result = calculateValueExEx<>(
        std::string("123"), std::string("456") );

    auto result2 = calculateValueExEx<std::string, std::string>("123", "456");
}

// ====================================================