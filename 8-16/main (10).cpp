//Programmer: Brianna Deirth
//Date: 7/26/2023
//Purpose: Program simulates a pick-5 lottery game. Generates and stores 5 distinct numbers between 1-9 into an array. Then the program prompts the player to neter five distinct numbers between 1-9 and stores them into another array. The program then compares and determines whether the two arrays are identical. If identical the player won, if not player lost.

#include <iostream>

using namespace std;

//Function prototypes
void pick5Numbers(int* numbers);
bool sequentialSearch(int element, int numbers[5]);

int main() {
    // Write your main here
    //declare variables
    int numbers[] = {1,2,3,4,5,6,7,8,9};
    int playerNumbers[5] = {0,0,0,0,0};

    pick5Numbers(numbers);
    cout << "Enter 5 distinct numbers between 1 & 9: " << endl;
    
    for (int i = 0; i < 5; i++) 
    {
        cin >> playerNumbers[i];
    }

    bool won = true;
    for (int i = 0; i < 5 && won; i++)
    {
      if (!sequentialSearch(playerNumbers[i], numbers))
      {
        //Players number is wrong
        won = false;
      }
    }
    //Output if player won or lost
    if (won) cout << "Player Won!" << endl;
    else cout << "Player lost!" << endl;

}

//definition for pick5Numbers Function
void pick5Numbers(int* numbers) {
  srand(time(0));
  //randomly shuffle numbers and only use first 5
  for (int i = 0; i < 5; i++) {
    int index = rand() % 9;
    //switch numbers in the array and shuffle
    int temp = numbers[index];
    numbers[index] = numbers[i];
    numbers[i] = temp;
  }
}

//definition for sequentialSearch Function
bool sequentialSearch(int element, int numbers[5]) {
  for (int i = 0; i < 5; i++) {
    if (numbers[i] == element)
      return true;
  }
  return false;
}
