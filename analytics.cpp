#include "analytics.h"

/**
 * @brief Displays menu to the user
 *
 */
void displayMenu()
{
    cout << "2015 National Survey of Recent College Graduates" << endl;
    cout << "1.  Top 10 Majors with the Highest Mean Salary" << endl;
    cout << "2.  Top 10 Majors with the Lowest Mean Salary" << endl;
    cout << "3.  Top 10 Majors with the Highest Median Salary" << endl;
    cout << "4.  Top 10 Majors with the Lowest Median Salary" << endl;
    cout << "5.  Top 5 Majors with the Highest Number of Asians" << endl;
    cout << "6.  Top 5 Majors with the Lowest Number of Asians" << endl;
    cout << "7.  Top 5 Majors with the Highest Number of Minorities" << endl;
    cout << "8.  Top 5 Majors with the Lowest Number of Minorities" << endl;
    cout << "9.  Top 5 Majors with the Highest number of Master's Degrees" << endl;
    cout << "10. Top 5 Majors with the Highest number of Doctorate's Degrees" << endl;
    cout << "11. Display Information for a Specific Major" << endl;
    cout << "12. Exit" << endl;
    cout << "\nSelect a Menu: ";
}

/**
 * @brief Makes sure a valid menu is chosen, while also returning chosen menu for further display.
 *
 * @return int
 */
int chooseMenu()
{
    while (true)
    {
        displayMenu();
        int choice = -1;
        cin >> choice;
        if (choice < 1 || choice > 12)
        {
            system("clear");
            cout << "--- That is an invalid menu option, please select a value 1 - 12 ---\n"
                 << endl;
        }
        else
        {
            return choice;
        }
    }
}

/**
 * @brief Switch cases for each menu option
 *
 * @param index
 */
void menuAction(int selectedIndex, vector<GradEmploymentData> &info)
{
    switch (selectedIndex)
    {
    case 1:
        highestMeanSalary(info, info.size());
        break;
    case 2:
        lowestMeanSalary(info, info.size());
        break;
    case 3:
        highestMedianSalary(info, info.size());
        break;
    case 4:
        lowestMedianSalary(info, info.size());
        break;
    case 5:
        highAsians(info, info.size());
        break;
    case 6:
        lowAsians(info, info.size());
        break;
    case 7:
        highMinorities(info, info.size());
        break;
    case 8:
        lowMinorities(info, info.size());
        break;
    case 9:
        highMaster(info, info.size());
        break;
    case 10:
        highDoctorate(info, info.size());
        break;
    case 11:
        mInfo(info);
        break;
    case 12:
        quit();
        break;
    }
}

void highestMeanSalary(vector<GradEmploymentData> &info, int size)
{
    system("clear");
    cout << "Education Major              Mean Salary (High)\n";
    cout << "-----------------------------------------------\n";
    sortHighMeanSalary(info, size);
}
void lowestMeanSalary(vector<GradEmploymentData> &info, int size)
{
    system("clear");
    cout << "Education Major               Mean Salary (Low)\n";
    cout << "-----------------------------------------------\n";
    sortLowMeanSalary(info, info.size());
}
void highestMedianSalary(vector<GradEmploymentData> &info, int size)
{
    system("clear");
    cout << "Education Major            Median Salary (High)\n";
    cout << "-----------------------------------------------\n";
    sortHighMedianSalary(info, info.size());
}
void lowestMedianSalary(vector<GradEmploymentData> &info, int size)
{
    system("clear");
    cout << "Education Major             Median Salary (Low)\n";
    cout << "-----------------------------------------------\n";
    sortLowMedianSalary(info, info.size());
}
void highAsians(vector<GradEmploymentData> &info, int size)
{
    system("clear");
    cout << "Education Major         Number of Asians (High)\n";
    cout << "-----------------------------------------------\n";
    sortHighAsians(info, info.size());
}
void lowAsians(vector<GradEmploymentData> &info, int size)
{
    system("clear");
    cout << "Education Major          Number of Asians (Low)\n";
    cout << "-----------------------------------------------\n";
    sortLowAsians(info, info.size());
}
void highMinorities(vector<GradEmploymentData> &info, int size)
{
    system("clear");
    cout << "Education Major     Number of Minorities (High)\n";
    cout << "-----------------------------------------------\n";
    sortHighMinorities(info, info.size());
}
void lowMinorities(vector<GradEmploymentData> &info, int size)
{
    system("clear");
    cout << "Education Major      Number of Minoroties (Low)\n";
    cout << "-----------------------------------------------\n";
    sortLowMinorities(info, info.size());
}
void highMaster(vector<GradEmploymentData> &info, int size)
{
    system("clear");
    cout << "Education Major              Number of Master's Degrees\n";
    cout << "-------------------------------------------------------\n";
    sortHighMasters(info, info.size());
}
void highDoctorate(vector<GradEmploymentData> &info, int size)
{
    system("clear");
    cout << "Education Major           Number of Doctorate's Degrees\n";
    cout << "-------------------------------------------------------\n";
    sortHighDoctorates(info, info.size());
}
void mInfo(vector<GradEmploymentData> &info)
{
    system("clear");
    cout << "Which Education Major would you like info on?\n";
    cout << "---------------------------------------------\n";
    majorInfo(info);
}
void quit()
{
    system("clear");
    cout << "You have exited the program.\n"
         << endl;
}

void read(ifstream &file, vector<GradEmploymentData> &info)
{
    string tempLine = "";    // Temporary line read
    getline(file, tempLine); // Reads (skips) first line, since I won't be using it
    while (file.peek() != EOF)
    {
        GradEmploymentData data;
        file >> data.demographicsTotal;
        char delim; // Creating deliminator since string doesn't know where to stop.
        file >> delim;
        if (file.peek() == '"')
        {
            file >> delim;
            getline(file, data.educationMajor, '"');
            file >> delim;
        }
        else
        {
            getline(file, data.educationMajor, ',');
        }

        file >> data.meanSalary;
        file >> delim;
        file >> data.medianSalary;
        file >> delim;
        file >> data.demographicsAsian;
        file >> delim;
        file >> data.demographicsMinority;
        file >> delim;
        file >> data.demographicsWhite;
        file >> delim;
        file >> data.demographicsFemales;
        file >> delim;
        file >> data.demographicsMales;
        file >> delim;
        file >> data.educationBachelor;
        file >> delim;
        file >> data.educationDoctorate;
        file >> delim;
        file >> data.educationMasters;
        file.get();

        info.push_back(data);
    }
}

void majorInfo(vector<GradEmploymentData> &info)
{
    int j = 1;
    for (int i = 0; i < 45; i++)
    {
        cout << j << ": ";
        cout << info[i].educationMajor << endl;
        j++;
    }
}

// All sorting functions for different fields

void sortHighMeanSalary(vector<GradEmploymentData> &info, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (info[j].meanSalary < info[j + 1].meanSalary)
            {
                swap(info[j], info[j + 1]);
            }
    }
    printVectMeanSalary(info);
}

void sortLowMeanSalary(vector<GradEmploymentData> &info, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (info[j].meanSalary > info[j + 1].meanSalary)
            {
                swap(info[j], info[j + 1]);
            }
    }
    printVectMeanSalary(info);
}

void sortHighMedianSalary(vector<GradEmploymentData> &info, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (info[j].medianSalary < info[j + 1].medianSalary)
            {
                swap(info[j], info[j + 1]);
            }
    }
    printVectMedianSalary(info);
}

void sortLowMedianSalary(vector<GradEmploymentData> &info, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (info[j].medianSalary > info[j + 1].medianSalary)
            {
                swap(info[j], info[j + 1]);
            }
    }
    printVectMedianSalary(info);
}

void sortHighAsians(vector<GradEmploymentData> &info, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (info[j].demographicsAsian < info[j + 1].demographicsAsian)
            {
                swap(info[j], info[j + 1]);
            }
    }
    printVectAsians(info);
}

void sortLowAsians(vector<GradEmploymentData> &info, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (info[j].demographicsAsian > info[j + 1].demographicsAsian)
            {
                swap(info[j], info[j + 1]);
            }
    }
    printVectAsians(info);
}

void sortHighMinorities(vector<GradEmploymentData> &info, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (info[j].demographicsMinority < info[j + 1].demographicsMinority)
            {
                swap(info[j], info[j + 1]);
            }
    }
    printVectMinorities(info);
}

void sortLowMinorities(vector<GradEmploymentData> &info, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (info[j].demographicsMinority > info[j + 1].demographicsMinority)
            {
                swap(info[j], info[j + 1]);
            }
    }
    printVectMinorities(info);
}

void sortHighMasters(vector<GradEmploymentData> &info, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (info[j].educationMasters < info[j + 1].educationMasters)
            {
                swap(info[j], info[j + 1]);
            }
    }
    printVectMasters(info);
}

void sortHighDoctorates(vector<GradEmploymentData> &info, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (info[j].educationDoctorate < info[j + 1].educationDoctorate)
            {
                swap(info[j], info[j + 1]);
            }
    }
    printVectDoctorates(info);
}

// Print Functions

void printVectMeanSalary(vector<GradEmploymentData> &info)
{
    for (int i = 0; i < 10; i++)
    {
        cout << left << setw(36) << info[i].educationMajor << fixed << "$" << right << setw(10) << setprecision(2) << info[i].meanSalary << endl;
    }
}

void printVectMedianSalary(vector<GradEmploymentData> &info)
{
    for (int i = 0; i < 10; i++)
    {
        cout << left << setw(36) << info[i].educationMajor << fixed << "$" << right << setw(10) << setprecision(2) << info[i].medianSalary << endl;
    }
}

void printVectAsians(vector<GradEmploymentData> &info)
{
    for (int i = 0; i < 5; i++)
    {
        cout << left << setw(36) << info[i].educationMajor << fixed << right << setw(11) << setprecision(2) << info[i].demographicsAsian << endl;
    }
}

void printVectMinorities(vector<GradEmploymentData> &info)
{
    for (int i = 0; i < 5; i++)
    {
        cout << left << setw(36) << info[i].educationMajor << fixed << right << setw(11) << setprecision(2) << info[i].demographicsMinority << endl;
    }
}

void printVectMasters(vector<GradEmploymentData> &info)
{
    for (int i = 0; i < 5; i++)
    {
        cout << left << setw(36) << info[i].educationMajor << fixed << right << setw(19) << setprecision(2) << info[i].educationMasters << endl;
    }
}

void printVectDoctorates(vector<GradEmploymentData> &info)
{
    for (int i = 0; i < 5; i++)
    {
        cout << left << setw(36) << info[i].educationMajor << fixed << right << setw(19) << setprecision(2) << info[i].educationDoctorate << endl;
    }
}