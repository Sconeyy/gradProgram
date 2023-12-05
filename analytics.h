#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct GradEmploymentData
{
    int demographicsTotal;    // The estimated total of people awarded degrees in this major during 2005
    string educationMajor;    // The name of the major for these graduated students
    float meanSalary;         // The average (mean) recorded salary reported for employed people with this degree
    float medianSalary;       // The median recorded salary reported for employed people with this degree
    int demographicsAsian;    // The estimated number of Asians awarded degrees in this major
    int demographicsMinority; // The estimated number of minorities awarded degrees in this major
    int demographicsWhite;    // The estimated number of Whites awarded degrees in this major
    int demographicsFemales;  // The estimated number of women awarded degrees in this major
    int demographicsMales;    // The estimated number of men awarded degrees in this major
    int educationBachelor;    // The estimated number of bachelor degrees awarded in this for major
    int educationDoctorate;   // The estimated number of doctoral degrees awarded in this for major
    int educationMasters;     // The estimated number of masters degrees awarded in this for major
};

// Function prototypes
void displayMenu();
int chooseMenu();
void menuAction(int selectedIndex, vector<GradEmploymentData> &info);
// Menu option prototypes
void highestMeanSalary(vector<GradEmploymentData> &info, int size);
void lowestMeanSalary(vector<GradEmploymentData> &info, int size);
void highestMedianSalary(vector<GradEmploymentData> &info, int size);
void lowestMedianSalary(vector<GradEmploymentData> &info, int size);
void highAsians(vector<GradEmploymentData> &info, int size);
void lowAsians(vector<GradEmploymentData> &info, int size);
void highMinorities(vector<GradEmploymentData> &info, int size);
void lowMinorities(vector<GradEmploymentData> &info, int size);
void highMaster(vector<GradEmploymentData> &info, int size);
void highDoctorate(vector<GradEmploymentData> &info, int size);
void mInfo(vector<GradEmploymentData> &info);
void quit();

void read(ifstream &file, vector<GradEmploymentData> &info);
void majorInfo(vector<GradEmploymentData> &info);

void print(GradEmploymentData data);

void sortHighMeanSalary(vector<GradEmploymentData> &info, int n);
void sortLowMeanSalary(vector<GradEmploymentData> &info, int n);
void sortHighMedianSalary(vector<GradEmploymentData> &info, int n);
void sortLowMedianSalary(vector<GradEmploymentData> &info, int n);
void sortHighAsians(vector<GradEmploymentData> &info, int n);
void sortLowAsians(vector<GradEmploymentData> &info, int n);
void sortHighMinorities(vector<GradEmploymentData> &info, int n);
void sortLowMinorities(vector<GradEmploymentData> &info, int n);
void sortHighMasters(vector<GradEmploymentData> &info, int n);
void sortHighDoctorates(vector<GradEmploymentData> &info, int n);

void printVectMeanSalary(vector<GradEmploymentData> &info);
void printVectMedianSalary(vector<GradEmploymentData> &info);
void printVectAsians(vector<GradEmploymentData> &info);
void printVectMinorities(vector<GradEmploymentData> &info);
void printVectMasters(vector<GradEmploymentData> &info);
void printVectDoctorates(vector<GradEmploymentData> &info);

#endif