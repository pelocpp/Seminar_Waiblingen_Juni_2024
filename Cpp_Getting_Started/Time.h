#pragma once

class Time
{
    friend bool operator== (const Time& left, const Time& right);

    // friend class Point;

private:
    // member data / instance variables
    int m_hours;
    int m_minutes;
    int m_seconds;

    int milliseconds;


public:
    // c'tor
    Time();
    Time(int hours, int minutes, int seconds);

public:
    // getter / setter

    // 3 Stunden 5 Minuten ==> 185 
    // eine "berechnete Eigenschaft" // computed property
    int totalMinutes() { return 60 * m_hours + m_minutes; }

    void setHours(int hours);
    int getHours() const;

    void setMinutes(int minutes);
    void setSeconds(const int& seconds); // I wouldn't do this

    void setMilliseconds(int msecs);

    int getMinute() const;
    int getSeconds() const;

    // void getHours(int& hours);

    void getState(int& hours, int& minutes, int& seconds) const;


public:
    // operator
    // bool operator ==(const Time& other) const;

public:
    // public interface / methods
    void reset();
    void increment();
    void print() const;

    // bool equals(Time other);

    bool equals(const Time& other) const;
};

// ===================================================

bool operator== (const Time& left, const Time& right);