// ===========================================================================
// Rectangle.cpp
// ===========================================================================

#include "Rectangle.h"

namespace Rectangles {

    // c'tor(s)
    Rectangle::Rectangle(double x, double y, double width, double height) 
         : m_point (x, y), m_anotherPoint(3, 4)       // KONSTRUKTOR
        // : m_point()          // Standard-Konstruktor
    {
        //m_x = x;
        //m_y = y;

        // m_point = Point (x, y);  // WERTZUWEISUNG

        //// oder
        //Point tmp(x, y);
        //m_point = tmp;


        if (width >= 0.0) {
            m_width = width;
        }
        else {
            m_width = 0.0;
        }

        if (height >= 0.0) {
            m_height = height;
        }
        else {
            m_height = 0.0;
        }
    }

    // note constructor chaining
    Rectangle::Rectangle()
        : Rectangle(0.0, 0.0, 0.0, 0.0)
    {}


    // getter/setter
    //double Rectangle::getX() { return m_x; }
    //double Rectangle::getY() { return m_y; }
    double Rectangle::getX() { return m_point.getX(); }
    double Rectangle::getY() { return m_point.getY(); }
    double Rectangle::getWidth() { return m_width; }
    double Rectangle::getHeight() { return m_height; }

    Point Rectangle::getPoint()
    {
        return m_point;
    }


    void Rectangle::setX(double x)
    {
        // m_x = x;
        m_point.setX(x);
    }

    void Rectangle::setY(double y)
    {
        // m_y = y;
        m_point.setY(y);
    }

    void Rectangle::setWidth(double width)
    {
        if (width >= 0.0) {
            m_width = width;
        }
        else {
            std::cout << "Expected positive value for 'width': " << width << std::endl;
        }
    }

    void Rectangle::setHeight(double height)
    {
        if (height >= 0.0) {
            m_height = height;
        }
        else {
            std::cout << "Expected positive value for 'height: " << height << std::endl;
        }
    }

    // methods
    void Rectangle::moveTo(double x, double y)
    {
        //m_x += x;
        //m_y += y;

        m_point.setX(m_point.getX() + x);
        m_point.setY(m_point.getY() + y);
    }

    bool Rectangle::equals(Rectangle other)
    {
        if (m_point.getX() != other.getPoint().getX()) {
            return false;
        }

        if (m_point.getY() != other.getPoint().getY()) {
            return false;
        }

        if (m_width != other.m_width) {
            return false;
        }

        if (m_height != other.m_height) {
            return false;
        }

        return true;
    }

    double Rectangle::circumference()
    {
        return 2.0 * (m_width + m_height);
    }

    double Rectangle::area()
    {
        return m_width * m_height;
    }

    bool Rectangle::isSquare()
    {
        bool result = (m_width == m_height);
        return result;
    }

    Point Rectangle::center()
    {
        double x = m_point.getX() + m_width / 2.0;
        double y = m_point.getY() - m_height / 2.0;
        Point result(x, y);
        return result;
    }


    double Rectangle::diagonal()
    {
        return std::sqrt(
            m_width * m_width + m_height * m_height
        );
    }

    Rectangle Rectangle::intersection(Rectangle rect)
    {
        //if (m_y + m_height < rect.m_y) {
        //    Rectangle empty;
        //    return empty;
        //}
        //else if (m_y > rect.m_y + rect.m_height) {
        //    Rectangle empty;
        //    return empty;
        //}

        //if (m_x + m_width < rect.m_x) {
        //    Rectangle empty;
        //    return empty;
        //}
        //else if (rect.m_x + rect.m_width < m_x) {
        //    Rectangle empty;
        //    return empty;
        //}

        //double left, width;

        //if (m_x < rect.m_x) {
        //    left = rect.m_x;
        //    width = m_x + m_width - left;
        //}
        //else {
        //    left = m_x;
        //    width = rect.m_x + rect.m_width - left;
        //}

        //double top, height;

        //if (m_y < rect.m_y) {
        //    top = rect.m_y;
        //    height = m_y + m_height - top;
        //}
        //else {
        //    top = m_y;
        //    height = rect.m_y + rect.m_height - top;
        //}

        // Rectangle result(left, top, width, height);

        Rectangle result;

        return result;
    }

    void Rectangle::print()
    {

        std::cout << "Rectangle: (" << getX() << ',' << getY() << "),(Width="
            << getWidth() << ", Height=" << getHeight() << ") " << std::endl;

        std::cout
            << "[Area=" << area()
            << ", Circumference=" << circumference()
            << ", IsSquare=" << isSquare() << ']' << std::endl;
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================
