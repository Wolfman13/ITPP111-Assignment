#include <iostream>
#include <algorithm>

int array[200]; // The  array

// A function that will fill the array with 200 random integers between 0 and a 1000
void fillArray(){
  int range = 1000 - 0 + 1; // The range of the randomly generated numbers

  // A for loop that will push each randomly generated integer to the array
  for(int i = 0; i < 201; i ++){
    int num = rand() % range + 0; // Random number generater
    array[i] = num; // Pushes the randomly generated number into the array
  }
}

// A function that sorts the elements in the array and reorganizes them from lowest to highest
void sortArray(){
  const int SIZE = 201; // The size + 1 of the array
  std::sort(array, array + SIZE); // Macro that reorganizes the array
}

int main(){
  fillArray(); // Fills array
  sortArray(); // Sorts array

  std::cout << "Highest ticket sales: " << array[200] << std::endl; // Prints highest ticket sales
  std::cout << "Lowest ticket sales: " << array[0] << std::endl; // Prints lowest ticket sales

  return 0;
}
