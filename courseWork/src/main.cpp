#include "Singleton.hpp"
#include "ui/mainScreen.hpp"
#include <ctime>

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