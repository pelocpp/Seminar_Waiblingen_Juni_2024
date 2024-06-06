#include <iostream>
#include <fstream>

void test_file_io()
{
    char line[256];
    std::ifstream file;

    // std::string fileName = "..\\..\\..\\..\\Topic_19_FileIO.cpp";

    std::string fileName = "C:\\Development\\Seminar_Waiblingen_Juni_2024\\Cpp_Getting_Started\\Cpp_Getting_Started\\Topic_19_FileIO.cpp";

//#define FILE_NAME_1 "..\\C_Introduction\\Tutorial\\CRT\\CRT.c"
//#define FILE_NAME_2 "C:\\Development\\Seminar_C_All_In_One_April_2024\\ErsteSchritte\\ErsteSchritte\\Datei_11.c"
//#define FILE_NAME_3 R"(C:\Development\Seminar_C_All_In_One_April_2024\ErsteSchritte\ErsteSchritte\Datei_11.c)"

    file.open(fileName);

    if (file.is_open()) {

        int lineNumber = 0;

        while (!file.eof()) {

            file.getline(line, sizeof(line));
            lineNumber++;
            std::cout << lineNumber << ": " << line << std::endl;
        }

        file.close();
    }
    else {
        std::cout << "Cannot find file " << fileName << '!' << std::endl;
    }
    

}


