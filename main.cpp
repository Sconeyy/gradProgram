#include "analytics.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream file("graduates2015.csv");
    // TODO: Test if open
    vector<GradEmploymentData> info;
    read(file, info);

    system("clear");
    int selectedIndex = chooseMenu();
    menuAction(selectedIndex, info);
}