#include <iostream> // printf


// ====================================================

// Java
//interface IRectangle
//{
//    void draw();
//
//    int n;
//};

// C++: Nachahmung eines Interfaces
struct IRectangle
{
    virtual void draw() = 0;
};

struct ICloneable
{
    virtual void clone() = 0;
};


// ====================================================


class Rectangle : public IRectangle, public ICloneable
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

    // abstrakte Methode
    virtual void draw() = 0;

    // public interface
    void eraseBackground()
    {
        std::cout << "  Rectangle::eraseBackground" << std::endl;
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

    void draw() override {

        std::cout << "ColoredRectangle::draw" << std::endl;
        std::cout << "color=" << m_color << std::endl;
    }

    void clone() override
    {
        // ....
    }
};

// Tabelle: ColoredRectangle Länge 1:   ColoredRectangle::draw (Adresse)



class TransparentRectangle : public Rectangle
{
private:
    double m_opacity;   // Grad der Durchsichtigkeit

public:
    // c'tor(s)
    TransparentRectangle() : TransparentRectangle(0, 0, 0, 0, 0.5) {}

    TransparentRectangle(int x, int y, int width, int height, double opacity)
        : Rectangle(x, y, width, height), m_opacity(opacity)
    {
    }

    void draw() override {

        std::cout << "TransparentRectangle::draw" << std::endl;
        std::cout << "Opacity=" << m_opacity << std::endl;
    }

    void clone() override
    {
        // ....
    }
};



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

void test_inheritance_03()
{
    ColoredRectangle cr1;
    ColoredRectangle cr2;

    TransparentRectangle tr1;
    TransparentRectangle tr2;

    // Polymorphismus

    IRectangle* rectangles[4] = { &cr1 , &tr1, &cr2, &tr2 };

    for (int i = 0; i < 4; ++i ) {

        rectangles[i]->draw();
    }
}

void test_inheritance_04()
{
    Rectangle* r = nullptr;

    IRectangle* ir = nullptr;
}

void test_inheritance()
{
    test_inheritance_03();
}

