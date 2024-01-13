// Programmer: Brianna Deirth
// Date: 07/25/2023
// Description: Array program that takes in 20 numbers, doubles the array
// and stores in an array named Beta, stores the results of these two arrays 
// in an array named matrix. Print the 1D, 15 elements per line.
// Write a function to print the elements in the 2D or matrix array.

#include <iostream>
#include <iomanip>

using namespace std;

// Prototypes for Arrays

void inputArray(int list[], int size);
void printArray(const int list[], int size);
void doubleArray(const int list1[], int list2[], int size);
void copyAlphaBeta(int twoDim[][4], const int list1[], const int list2[], int rows);
void printTwoDim(const int twoDim[][4], int rows);

int main()
	{
	   int alpha[20];
	   int beta[20];
	   int matrix[10][4];

     //Calling inputArray Function
     inputArray(alpha, 20);
     cout << endl;
     cout << "Alpha after reading 20 numbers" << endl;

     //Calling printArray Function
     printArray(alpha, 20);
     cout << "***************************************" 
      << endl << endl;

     //Calling the doubleArray Function
     doubleArray(alpha, beta, 20);
     cout << "Beta after reading 20 numbers" << endl;

     //Calling the printArray Function
     printArray(beta, 20);
     cout << "****************************************" 
      << endl << endl;

     //Calling the copyAlphaBeta Function
     copyAlphaBeta(matrix, alpha, beta, 10);

     //Calling the 2D printArray Function
     cout << "Matrix after call to copyAlphaBeta" << endl;
     printTwoDim(matrix, 10);
     cout << "*******************************************" << endl << endl;

     return 0;
	}

// Function Definitions

//Input Array Data
void inputArray(int list[], int size)
{
  int i;

  cout << "Enter" << " " << size << " " << "integers" << endl;
  for (i = 0; i < size; i++)
    cin >> list[i];
}

//Print 1D array data
void printArray(const int list[], int size)
{
  int i;

  for (i = 0; i < size; i++)
  {
    cout << list[i] << " ";

    //Makes the printing of numbers break at 15
    if ((i + 1) % 15 == 0)
          cout << endl;
  }
  cout << endl;
}

// Doubles each array element and stores in Beta
void doubleArray(const int list1[], int list2[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    list2[i] = 2 * list1[i];
}

// Copies Alpha and Beta into Matrix
void copyAlphaBeta(int twoDim[][4], const int list1[], const int list2[], int rows)
{
  int i, j;

  //reading and storing alpha elements into matrix
  for (i = 0; i < 5; i++)
    for (j = 0; j < 4; j++)
      twoDim[i][j] = list1[4 * i + j];

  // reading and storing beta elements into matrix
  for (i = 0; i < rows; i++)
    for (j = 0; j < 4; j++)
      twoDim[i][j] = list2[4 * (i - 5) + j];
}

// Print the two dimensional array elements
void printTwoDim(const int twoDim[][4], int rows)
{
  int i, j;

  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < 4; j++)
      cout << setw(8) << twoDim[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}
