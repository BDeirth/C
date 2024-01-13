//Programmer: Brianna Deirth
//Date: 07/17/2023
//Purpose: This program reads the names from file "Ch7_Ex9Data.txt" and outputs them into first, middle, last form instead of last, first, middle.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//declare getName function
void getName();

int main() {
    // Write your main here
    getName();

    system("pause");
    return 0;
}

//getName function definition
void getName()
{
    //declare variables
    string fullName;
    ifstream inData;
    string lastName;
    string middleName;
    string firstName;
    int none;
    int nothing;

    //open file
    inData.open("Ch7_Ex9Data.txt");
    do
    {
            getline(inData, fullName);
            none = fullName.find(","); //using find to find index of ,
            lastName = fullName.substr(0, none); //using substr to extract last names
            nothing = fullName.length(); //using length to find the length of the string
            firstName = fullName.substr(none + 2, nothing); //using substring to extract first and middle names
            cout << firstName << " " << lastName << endl; //displaying the names
    }
    while (inData.eof() == false); //while loop for reading whole file
    inData.close(); //close file
}
