// Tugas PTI 14 Desember
// Claudio Hans Figo
// 22.12.2321

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

using namespace std;

// c = 7 for default color
void setConsoleColor(WORD c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main()
{
    // setConsoleColor(FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED );
    setConsoleColor(3);
    std::cout << "Hello\n";
    setConsoleColor(2);
    std::cout << "Goodbye\n";
    // setConsoleColor(8);
}
