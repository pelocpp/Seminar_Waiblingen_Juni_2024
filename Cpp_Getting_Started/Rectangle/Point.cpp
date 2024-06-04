// ===========================================================================
// Point.cpp
// ===========================================================================

#include "Point.h"

namespace Rectangles {

    // c'tor(s)
    // constructor chaining
    Point::Point() : Point(0, 0) {}

    // member wise initialization
    // Point::Point(double x, double y) : m_x(x), m_y(y) {}

    Point::Point(double x, double y)
    {
        // this(...);  // Java-like

        m_x = x;
        m_y = y;
    }

    // getter/setter
    double Point::getX() { return m_x; }
    double Point::getY() { return m_y; }

    void Point::setX(double x) { m_x = x; }
    void Point::setY(double y) { m_y = y; }
}

// ===========================================================================
// End-of-File
// ===========================================================================
