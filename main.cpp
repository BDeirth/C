/*    Name: Brianna Deirth
*     Date: 01/12/2024
*     Purpose: A company hired 10 temporary workers who are paid hourly and you are
*     given a data file that contains the last name of the employees, the number of
*     hours each employee worked in a week, and the hourly pay rate of each
*     employee. You are asked to write a program that computes each employee’s
*     weekly pay and the average salary of all
*     employees. The program then outputs the weekly pay of each employee,
*     the average weekly pay, and the names of all the employees whose pay is 
*     greater than or equal to the average pay. If the number of hours worked in
*     a week is more than 40, then the pay rate for the hours over 40 is 1.5 times
*     the regular hourly rate.
*/

// Libraries
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int ROWS = 10;
const int COLS = 3;


// Function Prototypes
void getData(ifstream& infile, string names[ROWS], double hrsWorked[ROWS][COLS]);
void calculateSalary(double hrsWorked[ROWS][COLS]);
void printEmpData(string names[ROWS], double hrsWorked[ROWS][COLS]);
double calculateAvgSalary(double hrsWorked[ROWS][COLS]);
void printEmpSalaryGreaterThanAvg(string names[ROWS], double hrsWorked[ROWS][COLS]);


int main() {

    // Declare Variables
    string names[ROWS];
    double hrsWorked[ROWS][COLS];

    ifstream infile;     // input file stream variable
    ofstream outfile;    // output file stream variable

    infile.open("ch8_Ex17Data.txt");
    if (!infile)
    {
        cout << "Cannot open the input file. ";
        return 1;
    }

    outfile.open("out.txt");

    //set up output line
    cout << fixed << showpoint << setprecision(2);

    // call to getData Function
    getData(infile, names, hrsWorked);
    calculateSalary(hrsWorked);
    printEmpData(names, hrsWorked);
    printEmpSalaryGreaterThanAvg(names, hrsWorked);

}

// getData function definition
void getData(ifstream& infile, string names[ROWS], double hrsWorked[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        infile >> names[i];
        for (int j = 0; j < COLS - 1; j++)
            infile >> hrsWorked[i][j];
    }
}  //end of getData function

// calculateSalary function
void calculateSalary(double hrsWorked[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        if (hrsWorked[i][0] < 40)
            hrsWorked[i][2] = hrsWorked[i][0] * hrsWorked[i][1];
        else
            hrsWorked[i][2] = 40 * hrsWorked[i][1] + 1.5 * (hrsWorked[i][0] - 40) * hrsWorked[i][1];
    }
} // end calculateSalary function

// print employee data function
void printEmpData(string names[ROWS], double hrsWorked[ROWS][COLS])
{
    // formatting output line
    cout << left << setw(8) << "Name"
         << right << setw(10) << "Hrs Worked"
         << setw(10) << "Pay Rate"
         << setw(10) << "Salary" << endl;

    // Printing data
    for (int i = 0; i < ROWS; i++)
    {
        cout << left << setw(8) << names[i];
        cout << right;
        for (int j = 0; j < COLS; j++)
            cout << setw(10) << hrsWorked[i][j];
        cout << endl;
    }

    cout << endl;
}

// calculateAvgSalary function
double calculateAvgSalary(double hrsWorked[ROWS][COLS])
{
    // declaring and initializing a variable
    double sum = 0.0;

    for (int i = 0; i < ROWS; i++)
        sum = sum + hrsWorked[i][2];

    return sum / ROWS;
}

// printEmpSalaryGreaterThanAvg function
void printEmpSalaryGreaterThanAvg(string names[ROWS], double hrsWorked[ROWS][COLS])
{
    // declaring variables
    double avgSalary;

    //calling average salary function
    avgSalary = calculateAvgSalary(hrsWorked);

    cout << "Average Salary: $" << avgSalary << endl << endl;

    cout << "Salary Greater than Avg:" << endl;
    cout << endl;

    for (int i = 0; i < ROWS; i++)
    if (hrsWorked[i][2] >= avgSalary)
        cout << names[i] << " ";
    cout << endl;
}