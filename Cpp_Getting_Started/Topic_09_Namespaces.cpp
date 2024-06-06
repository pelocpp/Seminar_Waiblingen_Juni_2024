#include <iostream>
// using namespace std;

namespace Project2024Redesign
{
    namespace Widgets
    {
        class Rectangle
        {

        };
    }

    namespace MockWidgets
    {
        class Rectangle
        {

        };
    }
}

namespace Project2024Widgets
{
    class Rectangle
    {

    };

    class Textbox
    {

    };

    class List
    {

    };
}

namespace Project2024TestWidgets
{
    class Rectangle
    {

    };

    class Textbox
    {

    };

    class List
    {

    };
}


// Mock Klassen

namespace Project2024MockWidgets
{
    class Rectangle
    {

    };

    class Textbox
    {

    };

    class List
    {

    };
}

// das machen wir nicht :-)))
// using namespace Project2024Widgets;


void test_namespaces_01()
{
    Project2024Widgets::Rectangle rect;

    Project2024Widgets::Textbox tb;
}



void test_namespaces_02()
{
    using namespace Project2024Widgets;

    Rectangle rect;

    Textbox tb;
}


void test_namespaces_03()
{
    using namespace Project2024TestWidgets;

    Project2024TestWidgets::Rectangle rect;

    Project2024Widgets::Textbox tb;
}


//void test_namespaces_04()
//{
//    Rectangle rect;
//
//    Textbox tb;
//
//    std::cout << "asdasdasd";
//}
//


void test_namespaces_04()
{
    using namespace Project2024Redesign::Widgets;

    ///Project2024Redesign::Widgets::Rectangle rect;

    Rectangle rect;
}
