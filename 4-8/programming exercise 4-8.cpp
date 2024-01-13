// Programmer: Brianna Deirth
// Date: 06/26/2023
// Purpose: This program mimics a calculator. It takes first and second integers as input followed by the operation to be performed and outputs the correct calculations. 

#include <iostream>

using namespace std;

int main() {

    // Declaring and initializing variables
    int firstNum, secondNum, solution;
    char operation;

    // input for calculations
    cout << "Enter your first integer: ";
    cin >> firstNum;

    cout << "Enter your second integer: ";
    cin >> secondNum;

    cout << "Enter operation to be performed (+, -, *, /): ";
    cin >> operation;
    
    // Switch statement to calculate the result based on user input
    switch(operation)
    {
      case '+': solution = firstNum + secondNum; //addition calculation
                break;

      case '-': solution = firstNum - secondNum; //subtraction calculation
                break;
          
      case '*': solution = firstNum * secondNum; //multiplication calculation
                break;

      case '/': 
        if (secondNum == 0) {
                cout << "Error: cannot divide by zero" << endl; //output if trying to divide by zero
                return 0;
        }
                solution = firstNum / secondNum; //division calculation
                break;

      default:  cout << "Error: please check your input and try again" << endl; //output for invalid entry
                return 0;
    }
    //output of calculation with solution
    cout << firstNum << ' ' << operation << ' ' << secondNum << " = " << solution << endl;
    return 0;
}
