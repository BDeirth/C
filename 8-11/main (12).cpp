//Programmer: Brianna Deirth
//Date: 07/26/2023
//Purpose: This program inputs two positive integers of, at most, 20 digits and outputs the sum of the numbers. If the sum of the numbers has more than 20 digits, the output displays the message "The sum of the numbers overflows".

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Prototypes for function and arrays
void readStoreArray(string, int [], int);
void total(int[], int[], int[], int);
  
int main()
{
  //declaring constants
  const int SIZE = 20; 

  //declaring and initializing variables
  string firstNumber; 
  string secondNumber;
  int number1[SIZE] = {0};
  int number2[SIZE] = {0};
  int sum[SIZE] = {0};
  
  bool zeros = false;

  //Input statements for collecting numbers
  cout << "Input two positive integers of, at most, 20 digits." << endl;
  cout << "Enter the first number: " << endl;
  cin >> firstNumber;
  cout << "Enter the second number: " << endl;
  cin >> secondNumber;

  //Storing input in our arrays
  readStoreArray(firstNumber, number1, SIZE); 
  readStoreArray(secondNumber, number2, SIZE); 
  total(sum, number1, number2, SIZE);

  //Output of sum if less than or equal to 20 digits
    cout << "The sum of the numbers = " << endl;
    for (int i = 0; i < SIZE; i++)
    {
      if (sum[i] != 0)
        zeros = true;
      if (zeros)
      {
          cout << sum[i];
      }
    }
    return 0;
}

// Function Definitions

//readStoreArray Definition
void readStoreArray(string input, int number[], int size) 
{ 
  int length = input.length();

  int index = 19;
   
  for (int i = length - 1; i >= 0; i--)
  {
      number[index] = input.at(i) - '0';
      index--;
  }
}

//total Definition
void total(int sum[], int number1[], int number2[], int size) 
{ 
  int remainder = 0; 
  for (int i = size - 1; i >= 0; i--) 
  { 
     if (i == 0 && remainder != 0) 
     { 
       //output if greater than 20 digits
       cout << "The sum of the numbers overflows" << endl;
    //end instead of printing out sum anyway
    exit(0); 
     } 
     
     sum[i] = remainder + ((number1[i] + number2[i]) % 10); 
     remainder = (number1[i] + number2[i]) / 10; 
  }
}
