#include <iostream>

extern void test_time_01();
extern void test_time_02();
extern void test_time_03();
extern void test_time_04();
extern void test_time_05();

extern void test_arrays_01();
extern void test_arrays_02();
extern void test_arrays_03();
extern void test_arrays_04();
extern void test_arrays_05();

extern void exerciseRectangle();
extern void exerciseStrings();

extern void test_chars_strings_01();
extern void test_chars_strings_02();
extern void test_chars_strings_03();
extern void test_chars_strings_04();
extern void test_chars_strings_05();
extern void test_chars_strings_06();
extern void test_chars_strings_07();

extern void test_references();
extern void test_raii();
extern void test_dynamic();
extern void main_dynamic_int_array();
extern void test_inheritance();
extern void test_templates();
extern void test_stl();


int main()
{
    // std::cout << "Hallo Cpp Seminar\n";

    test_stl();

    return 0;
}
