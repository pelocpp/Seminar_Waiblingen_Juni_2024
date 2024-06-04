#include <stdio.h>  // printf

#include <iostream> // std::cout
#include <string>   // std::string

void test_chars_strings_01()
{
    char ch = 'A';

    printf("%c\n", ch);

    // Symbiose : char  und int

    int n = ch;

    printf("%d\n", n);
}

void test_chars_strings_02()
{
    char ch = '\n';   // new Line

    printf("Vorher%cNachher\n", ch);

    //ch = 13;     // Carriage Return

    //printf("Vorherrrrrrrrrrrrrrrr%cNachher\n", ch);

    ch = 10;     // Line Feed

    printf("Vorherrrrrrrrrrrrrrrr%cNachher\n", ch);
}

void test_chars_strings_03()
{
    for (int i = 0; i < 127; ++i) {

        char ch = i;

        printf("%d: %c\n", i, ch);
    }
}

// ================================================

void test_chars_strings_04()
{
    // A)
    const char* s = "ABCDE";

    // B) Feld von Zeichen
    char zeichen[] = "12345";
}

void test_chars_strings_05()
{
    // A)
    const char* s = "ABCDE";
    // s[0] = 'a';

    // B) Feld von Zeichen
    char zeichen[] = "12345";
    zeichen[0] = '9';
}

void test_chars_strings_06()
{
    // A)
    const char* s = "ABCDE";
    // s[0] = 'a';

    char ch = '0';

    ch = 0;

    // oder

    ch = '\0';

    char zeichen[] = "12345";

    int n1 = sizeof(s);
    int n2 = sizeof(*s);

    char nochmalZeichen[30] = { 'A', 'B', 'C', 'D', 'E', '\0'};

    printf("Zeichenkette: %s\n", nochmalZeichen);
}

void test_chars_strings_07()
{
    // standard class 'std::string'

    // constructor
    std::string s("12345");

    // operator <<
    std::cout << s << std::endl;

    // getter: size
    size_t len = s.size();
    std::cout << "Length: " << len << std::endl;

    // getter: empty
    bool b = s.empty();  // ""
    std::cout << "Empty: " << std::boolalpha << b << std::endl;

    // method: insert  s = "12345"  
    // insert "ABC" at position 2  ==> "12ABC345"
    s.insert(2, "ABC");
    std::cout << "s.insert(2, \"ABC\") ==> " << s << std::endl;



    // method: append   "12ABC345!!!"
    // append "!!!"
    s.append("!!!");
    std::cout << "s.append(\"!!!\")    ==> " << s << std::endl;

    // comparison operators
    std::string s1("12345");
    std::string s2("12345");
    std::string s3("123456");

    bool b1 = (s1 == s2);
    bool b2 = (s1 == s3);

    std::cout << "s1 == s2           ==> " << std::boolalpha << b1 << std::endl;
    std::cout << "s1 == s3           ==> " << std::boolalpha << b2 << std::endl;

    // method: substr - retrieve a substring
    // first param = position of the first character to include
    // second param = length of the substring
    std::string sub = s1.substr(1, 3);
    std::cout << "s1.substr(1, 3)    ==> " << std::boolalpha << sub << std::endl;

    // index operator []
    s[2] = '?';
    std::cout << "s[2] = '?'         ==> " << s << std::endl;

    // method: append
    // append another std::string object
    std::string result;
    result = s1.append(s2);
    std::cout << "s1.append(s2)      ==> " << result << std::endl;

    // operator +
    // concatenating two strings (same as using method append)
    result = s1 + s3;
    std::cout << "s1 + s3            ==> " << result << std::endl;

    // converting a string to an integer
    std::string number("123");

    int value = std::stoi(number);
    std::cout << "std::stoi(\"123\")   ==> " << value << std::endl;

    char ch2 = 'A';
    bool b3 = std::isdigit(ch2);
}
