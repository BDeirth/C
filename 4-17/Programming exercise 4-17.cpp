// Author: Brianna Deirth
// Date: 06/28/2023
// Purpose: Samantha and Vikas are looking to buy a house in a new development. /////// After looking at various models, the three models they like are colonial, /////// // split-entry, and single-story.

// The builder gave them the base price and the finished area in square feet of the /// three models. They want to know the model(s) with the least price per
// square foot.


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // Declare Variables
    string houseName;

    double priceColonial;
    double priceSplitLevel;
    double priceSingleStory;

    double finishedAreaColonial;
    double finishedAreaSplitLevel;
    double finishedAreaSingleStory;

    double pricePerSquareFootColonial;
    double pricePerSquareFootSplitLevel;
    double pricePerSquareFootSingleStory;

// Format output line
cout << fixed << showpoint << setprecision(2);

// Take in information and perform calculations
// Colonial Style Home
    cout << "Enter the price for the Colonial model. ";
    cin >> priceColonial;
    cout << endl;

    cout << "Enter the finished area per square foot for the Colonial model. ";
    cin >> finishedAreaColonial;
    cout << endl;

    pricePerSquareFootColonial = priceColonial/finishedAreaColonial;

// Split-Level Style Home
    cout << "Enter the price for the Split-Entry model. ";
    cin >> priceSplitLevel;
    cout << endl;

    cout << "Enter the finished area per square foot for the Split-Level model. ";
    cin >> finishedAreaSplitLevel;
    cout << endl;

    pricePerSquareFootSplitLevel = priceSplitLevel/finishedAreaSplitLevel;

// Single-Story Style Home
    cout << "Enter the price for the Single Story model. ";
    cin >> priceSingleStory;
    cout << endl;

    cout << "Enter the finished area per square foot for the Single Story model. ";
    cin >> finishedAreaSingleStory;
    cout << endl;

    pricePerSquareFootSingleStory = priceSingleStory/finishedAreaSingleStory;

if (pricePerSquareFootColonial < pricePerSquareFootSplitLevel)
{
  if (pricePerSquareFootColonial < pricePerSquareFootSingleStory)
      cout << "The price per square foot of the colonial model is the least. " << endl;
  else if (pricePerSquareFootColonial > pricePerSquareFootSingleStory)
      cout << "The price per square foot of the single-story model is the least. " << endl;
  else
      cout << "The price per square foot of the colonial and single-story models tie for the least. " << endl;
}  // closing the main if

else if (pricePerSquareFootColonial > pricePerSquareFootSplitLevel)
{ 
  if (pricePerSquareFootSplitLevel < pricePerSquareFootSingleStory)
      cout << "The price per square foot of the split-entry model is the least. " << endl;
  else if (pricePerSquareFootSplitLevel > pricePerSquareFootSingleStory)
      cout << "The price per square foot of the single-story model is the least. " << endl;
  else 
      cout << "The price per square foot of the single-story and split-entry models tie for the least. " << endl;
} // closing the else if

else 
{
  if (pricePerSquareFootColonial == pricePerSquareFootSingleStory)
      cout << "The price per square foot all three models are the same. " << endl;
  else if (pricePerSquareFootColonial > pricePerSquareFootSingleStory)
      cout << "The price per square foot of the single-story model is the least. " << endl;
  else
    cout << "The price per square foot of the colonial and split-entry models tie for the least. " << endl;
}
  
    return 0;
}
