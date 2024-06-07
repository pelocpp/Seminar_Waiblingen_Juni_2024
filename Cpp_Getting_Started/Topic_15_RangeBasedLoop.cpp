#include <iostream>
#include <vector>
#include <algorithm>

void main_range_based_loop_01()
{
    std::vector numbers = { 1, 2, 3, 4, 5 };

    // A) std::for_each
    std::for_each(
        numbers.begin(), 
        numbers.end(),
        [](int n) { std::cout << n << '\n'; }
    );

    std::cout << '\n';

    // B) Range-Based for loop
    for (auto  n : numbers) {
        std::cout << n << '\n';
    }

    std::cout << '\n';

    // C) INTERN
    std::vector<int>::iterator pos = numbers.begin();
    std::vector<int>::iterator end = numbers.end();

    for (; pos != end; ++pos) {

        std::cout << "Value: " << *pos << '\n';
    }
}

// ================================================
// ================================================

class LottoZahlen
{
private:
    std::vector<int> m_numbers;

public:
    LottoZahlen() : m_numbers{ 11, 4, 13, 27, 19, 18 } {}

    std::vector<int>::iterator begin() { return m_numbers.begin(); }
    std::vector<int>::iterator end() { return m_numbers.end(); }
};

void main_range_based_loop_02()
{
    LottoZahlen ziehung;

    for (auto n : ziehung) {
        std::cout << "Kugel: " << n << '\n';
    }
}

// ================================================
// ================================================

//class LottoZahlenEx;
//class LottoZahlenIterator;

class LottoZahlenEx
{
private:
    std::vector<int> m_numbers;

public:
    LottoZahlenEx() : m_numbers{ 11, 4, 13, 27, 19, 18 } {}
    int getKugelAt(int index) { return m_numbers[index]; }

private:
    class LottoZahlenIterator
    {
    private:
        int            m_index;  // Wenn Index = 6: Keine Lottozahlen mehr, Ende der Iteration
        LottoZahlenEx& m_outer;

    public:
        LottoZahlenIterator(LottoZahlenEx& lottoZahlen, int index)
            : m_outer(lottoZahlen), m_index(index) {}

    public:
        int operator* () { return m_outer.getKugelAt(m_index); }

        void operator++ () { m_index++; }

        bool operator != (const LottoZahlenIterator& other) {
            return m_index != other.m_index;
        }
    };

public:
    LottoZahlenIterator begin() { return LottoZahlenIterator(*this, 0); }
    LottoZahlenIterator end() { return LottoZahlenIterator(*this, 6); }
};


void main_range_based_loop()
{
    LottoZahlenEx ziehung;

    for (auto n : ziehung) {
        std::cout << "Kugel: " << n << '\n';
    }
}
