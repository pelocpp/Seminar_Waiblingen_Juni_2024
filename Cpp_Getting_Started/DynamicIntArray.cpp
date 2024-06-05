#include <iostream>
#include <exception>

#include "DynamicIntArray.h"

DynamicIntArray::DynamicIntArray()
{
    m_length = 0;
    m_data = nullptr;
}

DynamicIntArray::DynamicIntArray(size_t length)
{
    m_data = new int[length];
    m_length = length;

    // Speicher mit 0 vorbelegen
    for (int i = 0; i < m_length; ++i) {
        m_data[i] = 0;
    }
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& other)
{
    // Länge umkopieren
    m_length = other.m_length;

    // neuen, separaten Puffer auf dem Heap für die Kopie anlegen
    m_data = new int[other.m_length];

    // Daten des Puffers umkopieren
    for (int i = 0; i < other.m_length; ++i) {
        m_data[i] = other.m_data[i];
    }

    // std::memcpy : nur bytes 
    // std::copy   : Umrechnung von int auf bytes
}

//DynamicIntArray::DynamicIntArray(const DynamicIntArray& other)
//{
//    *this = other;   // NEIN
//}

DynamicIntArray& DynamicIntArray::operator= (const DynamicIntArray& other)
{
    if (this != &other) {

        // die vorhandenen Daten sind freizugeben
        // linke Seite freigeben
        delete[] m_data;

        // Länge umkopieren
        m_length = other.m_length;

        // neuen, separaten Puffer auf dem Heap für die Kopie anlegen
        m_data = new int[other.m_length];

        // Daten des Puffers umkopieren
        for (int i = 0; i < other.m_length; ++i) {
            m_data[i] = other.m_data[i];
        }
    }

    return *this;
}

DynamicIntArray::~DynamicIntArray()
{
    delete[] m_data;
}

// getter / setter
//int DynamicIntArray::at(size_t index)
//{
//    if (index >= m_length) {
//        throw std::exception("Index out of bounds");
//    }
//
//    return m_data[index];
//}
//
//void DynamicIntArray::at(size_t index, int value)
//{
//    if (index >= m_length) {
//        throw std::exception("Index out of bounds");
//    }
//
//    m_data[index] = value;
//}

// getter / setter
int& DynamicIntArray::at(size_t index)
{
    if (index >= m_length) {
        throw std::exception("Index out of bounds");
    }

    return m_data[index];
}

size_t DynamicIntArray::size() const
{
    return m_length;
}

int& DynamicIntArray::operator[] (size_t index) const
{
    return m_data[index];
}

void DynamicIntArray::print()
{
    for (int i = 0; i < m_length; ++i) {
        //std::cout << i << ": " << (*this)[i] << std::endl;
        //std::cout << i << ": " << at(i) << std::endl;
        std::cout << i << ": " << m_data[i] << std::endl;
    }
}

void DynamicIntArray::fill(int value)
{
    for (int i = 0; i < m_length; ++i) {
        m_data[i] = value;
        //(*this)[i] = value;
        //at(i) = value;
    }
}

std::ostream& operator << (std::ostream& os, const DynamicIntArray& obj)
{
    for (int i = 0; i < obj.size(); ++i) {

        os << i << ": " << obj[i] << '\n';
    }

    return os;
}


void DynamicIntArray::resize(size_t newSize)
{
    if (newSize <= m_length) {

        // verkleinern - lazy
        m_length = newSize;
    }
    else {
        // vergrößern

        // A) Neuen, größeren Puffer anlegen
        int* tmp = new int[newSize];

        // B) alten Puffer in neuen Puffer umkopieren
        for (size_t i = 0; i < m_length; ++i) {

            tmp[i] = m_data[i];
        }

        // C) neuen Puffer "oben" mit 0 vorbelegen
        for (size_t i = m_length; i < newSize; ++i) {

            tmp[i] = 0;
        }

        // D) alten Puffer loeschen
        delete[] m_data;

        // E) Instanzvariablen aktualisieren
        m_data = tmp;
        m_length = newSize;
    }


}

