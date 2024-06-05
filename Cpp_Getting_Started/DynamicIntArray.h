#pragma once

class DynamicIntArray
{
private:
    size_t m_length;
    int*   m_data;

public:
    // c'tors
    DynamicIntArray();
    DynamicIntArray(size_t length);

    // Kopier-Konstruktor
    DynamicIntArray(const DynamicIntArray& other); 

    // d'tor
    ~DynamicIntArray();

    // getter / setter
    // ohne Referenz
    //int at(size_t index);
    //void at(size_t index, int value);

    size_t size() const;

    // mit Referenz - with bounds checking
    int& at(size_t index);

    // operators - no bounds checking
    int& operator[] (size_t index) const;

    DynamicIntArray& operator= (const DynamicIntArray& other);

    // public interface
    void print();
    void fill(int value);

    void resize(size_t newSize);
};


// globale Funktion
std::ostream& operator << (std::ostream& os, const DynamicIntArray& obj);

