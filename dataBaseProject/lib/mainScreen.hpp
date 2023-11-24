#pragma once

#include <iostream>
#include <conio.h>

#include "listScreen.hpp"
// #include "sortedScreen.hpp"
// #include "searchScreen.hpp"
// #include "treeScreen.hpp"

void printMainMenuOption()
{
    std::cout << "<1> : Quit program"
              << "\t"
              << "<2> : Default list"
              << "\t"
              << "<3> : Sorted list"
              << "\t"
              << "<4> : Search"
              << std::endl;
}

void mainScreen()
{
    bool quitLoop = false;
    while (!quitLoop)
    {
        system("cls");
        printMainMenuOption();

        switch (getch())
        {
        case '1':
            quitLoop = true;
            break;
        case '2':
            listScreen();
            break;
        case '3':
            // sortedScreen();
            break;
        case '4':
            // searchScreen();
            break;
        }
    }
}