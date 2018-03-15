/*
David Chen
2018 C++
Heap Program
*/

#include "heap.h"
#include <cstring>
#include <fstream>

using namespace std;

int main() {

  //variable declarations
  heap heap;
  int to_add;
  int counter;
  char method[10], fileName[30];

  cout << "Enter series of numbers (S) or file name (F)?" << endl;
  cin >> method;

  if (!strcmp(method, "S")) {
    cout << "How many numbers?" << endl;
    cin >> counter;
    cout << "Enter the space-separated list." << endl;

    //add elements with for loop.  cin will not work
    for (int i = 0; i < counter; i++) {
      cin >> to_add;
      heap.add(to_add); //calls the add function in heap.cpp
    } //for loop

  } else if (!strcmp(method, "F")) {

    //this code is adapted from an excerpt found online for text file input

    ifstream inFile;

      cout << "What is the name of the file?" << endl;
      cin >> fileName;
      inFile.open(fileName);
      if (!inFile) {
	cout << "ERROR: No such file." << endl;
	return 0;
      }
      
      cout << "How many numbers?" << endl;
      cin >> counter;

      for (int i = 0; i < counter; i++) {
	inFile >> to_add;
	heap.add(to_add);
      }
      
      inFile.close();
  }

  //calling the other functions
  
    heap.printTree(counter);

    heap.printList();
}
