#include "Time.h"

void test_time_01()
{
    Time now (15, 52, 33);

    Time than;

    than.reset();

    //now.m_hours = 9999;
    //now.m_minutes = 52;
    //now.m_seconds = 33;

    now.setHours(16);
    int currentHours = now.getHours();
}


void test_time_02()
{
    Time now(9, 32, 33);

    Time pause(10, 30, 0); 

    bool b = now.equals(pause);
}


void test_time_03()
{
    Time now(10, 15, 20);

    //int neueMinuten = 16;
    int neueSekunden = 59;

    now.setMinutes(16);
    now.setSeconds(59);   // geht bei const Referenz
}

void test_time_04()
{
    Time now(10, 15, 20);

    //A) Demo 
    int hours;
   // now.getHours(hours);

    //B) Demo 
    hours = now.getHours();

    // BESSER
    int minutes;
    int seconds;

    now.getState(hours, minutes, seconds);
}



void test_time_05()
{
    Time now(9, 32, 33);

    Time pause(10, 30, 0);

    bool b = now.equals(pause);

    // oder / versus

    // Infix-Notation
    if (now == pause) {
        ; // .....
    }

    // Methodenaufruf
    //if (now.operator== (pause) ) {

    //}

    if (operator== (now, pause) ) {

    }
}
