#include <iostream>

#include "Time.h"

Time::Time()
{
    m_hours = 0;
    m_minutes = 0;
    m_seconds = 0;
}

Time::Time(int hours, int minutes, int seconds)
{
    m_hours = hours;
    m_minutes = minutes;
    m_seconds = seconds;
}

// getter / setter
void Time::setHours(int hours)
{
    if (hours >= 0 && hours < 24) {
        m_hours = hours;
    }
    else {
        throw std::exception("");
    }
}

int Time::getHours() const 
{
    return m_hours;
}

int Time::getMinute() const
{
    return m_minutes;
}

int Time::getSeconds() const
{
    return m_seconds;
}


// oder // aber nicht zu empehlen

void Time::getState(int& hours, int& minutes, int& seconds) const
{
    hours = m_hours;
    minutes = m_minutes;
    seconds = m_seconds;
}

// Java-stylistic
void Time::setMilliseconds(int milliseconds)
{
    //int n = 123;
    //this->n = 123;

    // Time::milliseconds = milliseconds;

    (*this).milliseconds = milliseconds;

    // oder, besser lesbarer:
    this->milliseconds = milliseconds;
}

// C++-stylistic
void Time::setMinutes(int minutes)
{
    m_minutes = minutes;
}

void Time::setSeconds(const int& seconds)
{
    m_seconds = seconds;
}


void Time::reset()
{
    m_hours = 0;
    m_minutes = 0;
    m_seconds = 0;
}

void Time::increment()
{
    // eine Uhrzeit um 1 Sekunden erhoehen ...
    // very, very simple - often wrong !!!!
    m_seconds = m_seconds + 1;
}

void Time::print() const
{
    std::cout << m_hours << ":" << m_minutes << ":" << m_seconds << '\n';

    //  std::endl: den internen Puffer leeren // flush
    std::cout << m_hours << ":" << m_minutes << ":" << m_seconds << std::endl;
}

//bool Time::equals(const Time& other) const
//{
//    // NUR ZUM TEST:
//    // other.m_seconds = 59;
//    // m_seconds = 59;
//
//    if (m_hours != other.m_hours) {
//        return false;
//    }
//
//    if (m_minutes != other.m_minutes) {
//        return false;
//    }
//
//    if (m_seconds != other.m_seconds) {
//        return false;
//    }
//
//    return true;
//}

bool Time::equals(const Time& other) const
{
    // NUR ZUM TEST:
    // other.m_seconds = 59;
    // m_seconds = 59;

    if (m_hours != other.getHours ()) {
        return false;
    }

    if (m_minutes != other.m_minutes) {
        return false;
    }

    if (m_seconds != other.m_seconds) {
        return false;
    }

    return true;
}

// operator
//bool Time::operator ==(const Time& other) const
//{
//    if (m_hours != other.getHours()) {
//        return false;
//    }
//
//    if (m_minutes != other.m_minutes) {
//        return false;
//    }
//
//    if (m_seconds != other.m_seconds) {
//        return false;
//    }
//
//    return true;
//}

// ===============================================================

//bool operator== (const Time& left, const Time& right)
//{
//    if (left.getHours() != right.getHours()) {
//        return false;
//    }
//
//    if (left.getMinute() != right.getMinute()) {
//        return false;
//    }
//
//    if (left.getSeconds() != right.getSeconds()) {
//        return false;
//    }
//
//    return true;
//}

bool operator== (const Time& left, const Time& right)
{
    if (left.m_hours != right.m_hours) {
        return false;
    }

    if (left.m_minutes != right.m_minutes) {
        return false;
    }

    if (left.m_seconds  != right.m_seconds) {
        return false;
    }

    return true;
}

// Vorwartsdeklaration
//class PointEx;
//
//bool operator== (const Time& left, PointEx right)
//{
//    return false;
//}

// =======================================================

// C++
class Node
{
public:
    int   m_data;
    Node* m_next;
    // ..........
};

// ===============================================================

