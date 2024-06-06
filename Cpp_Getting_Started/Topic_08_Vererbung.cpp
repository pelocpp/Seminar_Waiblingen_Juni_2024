#include <iostream> // printf

class Rectangle
{
private:
    int m_x;
    int m_y;
    int m_width;
    int m_height;

public:
    // c'tor(s)
    Rectangle() : Rectangle(0, 0, 0, 0) {}

    Rectangle(int x, int y, int width, int height)
        : m_x(x), m_y(y), m_width(width), m_height(height)
    {}

    // getter
    int getX() const { return m_x; }
    int getY() const { return m_y; }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

    void setX(int x) { m_x = x; }

    // public interface
    void eraseBackground()
    {
        std::cout << "  Rectangle::eraseBackground" << std::endl;
    }

    virtual void draw() {

        std::cout
        << "Rectangle::draw [x=" << m_x
        << ", y=" << m_y << "]" << std::endl;

        eraseBackground();
    }
};

// Tabelle: Rectangle Länge 1:   draw (Adresse)


class ColoredRectangle : public Rectangle
{
private:
    int m_color;   // Farbmodelle

public:
    // c'tor(s)
    ColoredRectangle() : ColoredRectangle(0, 0, 0, 0, 0) {}

    ColoredRectangle(int x, int y, int width, int height, int color)
        : Rectangle (x, y, width, height), m_color(color)
    {
        //m_x = x;   // wegen protected
        //setX(x);
        
        // ...
        m_color = color;
    }

    void draw() {

        std::cout << "ColoredRectangle::draw" << std::endl;
        Rectangle::draw();
        std::cout << "color=" << m_color << std::endl;
    }
};

// Tabelle: ColoredRectangle Länge 1:   ColoredRectangle::draw (Adresse)



void test_inheritance_01()
{
    ColoredRectangle cr(1, 1, 10, 20, 99);

    // cr.Rectangle::draw();
    cr.draw();
}




void test_inheritance_02()
{
    Rectangle* rp;

    ColoredRectangle cr(1, 1, 10, 20, 99);

    rp = &cr;

    rp->draw();    // Rectangle::draw: rp ist vom Typ Rectangle
                   // ColoredRectangle::draw: Das Objekt ist ein ColoredRectangle

    rp->eraseBackground();

}




void test_inheritance()
{
    test_inheritance_02();
}

