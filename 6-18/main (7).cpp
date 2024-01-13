//Programmer: Brianna Deirth
//Date: 07/12/2023
//Purpose: The program asks for input of employees name, arrival time, and departure time. Then the program outputs the total time an employee spent on the job each day.

#include <iostream>
#include <string>

using namespace std; 

    //function prototype
    void timeOnJob(int arvHr, int arvMin, bool arvIsAM, int depHr, int depmin, bool depIsAM);

int main()
{ 
   //declare variables
    string employeeName;
    
    int arrivalHr;
    int arrivalMin;
    bool arrivalAM;
    
    int departureHr;
    int departureMin;
    bool departureAM;
    
    char response;
    char discard;
    char isAM;
    
    //user input to run program
    cout << "This program calculates the total time spent by an "
         << "employee on the job." << endl;
    cout << "To run the program, enter (y/Y: ";
    cin >> response;
    cout << endl;
    cin.get(discard);

    //while loop to run program if user enters y/Y
    while (response == 'y' || response == 'Y')
    {
      //employee name input
        cout << "Enter employee's name: ";
        getline(cin, employeeName);
        cout << endl;

      //arrival info input
        cout << "Enter arrival hour: ";
        cin >> arrivalHr;
        cout << endl;

        cout << "Enter arrival minute: ";
        cin >> arrivalMin;
        cout << endl;

        cout << "Enter (y/Y) if arrival is before 12:00PM: ";
        cin >> isAM;
        cout << endl;

        if (isAM == 'y' || isAM == 'Y')
            arrivalAM = true;
        else
            arrivalAM = false;

      //departure info input
        cout << "Enter departure hour: ";
        cin >> departureHr;
        cout << endl;

        cout << "Enter departure minute: ";
        cin >> departureMin;
        cout << endl;

        cout << "Enter (y/Y) if departure is before 12:00PM: ";
        cin >> isAM;
        cout << endl;

        if (isAM == 'y' || isAM == 'Y')
            departureAM = true;
        else
            departureAM = false;

        //output of results
        cout << employeeName << endl; 
        timeOnJob(arrivalHr, arrivalMin, arrivalAM,
                 departureHr, departureMin, departureAM);
        
        //prompt user to run program again
        cout << "Run program again (y/Y): ";
        cin >> response;
        cout << endl;
        cin.get(discard);
    }
    return 0; //end of program
}
//timeOnJob function definition
void timeOnJob(int arvHr, int arvMin, bool arvIsAM,
               int depHr, int depMin, bool depIsAM)
{
    //declare variables
    int arvTimeInMin;
    int depTimeInMin;
    int timeOnJobInMin;

    arvTimeInMin = arvHr * 60 + arvMin;
    depTimeInMin = depHr * 60 + depMin;

    //if, else if, else statements
    if ((arvIsAM == true && depIsAM == true)
       || (arvIsAM == false && depIsAM == false))
    {
        if (arvTimeInMin <= depTimeInMin)
        {
           timeOnJobInMin = depTimeInMin - arvTimeInMin;
           cout << "Time spent of job: "
             << timeOnJobInMin / 60 << " hour(s) and "
             << timeOnJobInMin % 60 << " minutes." << endl;
        }
        else
           cout << "Invalid input." << endl;
    }      
        else if (arvIsAM == true && depIsAM == false) 
        {
           timeOnJobInMin = (720 - arvTimeInMin) + depTimeInMin;
           cout << "Time spent of job: "
             << timeOnJobInMin / 60 << " hour(s) and "
             << timeOnJobInMin % 60 << " minutes." << endl;
        }
        else 
        {
           cout << "Invalid input." << endl;
        }
}
