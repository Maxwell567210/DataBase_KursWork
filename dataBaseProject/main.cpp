#include <iostream>
#include <ctime>

#include "lib/mainScreen.hpp"
#include "lib/Singleton.hpp"

using namespace std;

void setupMainSettings()
{
    system("chcp 866 > nul");
    srand(time(nullptr));
}

int main()
{
    setupMainSettings();
    mainScreen();
    singleton.clear();
}