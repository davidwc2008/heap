#include <iostream>
#include <cmath>
#include <algorithm> //for swap (swaps two elements in an array)

using namespace std;

//header guard
#pragma once

class heap {
 protected:
  int size;
  int input[100];

 public:
  heap(); //constructor -- various functions below
  void add(int);
  void printTree(int);
  int rows();
  int spaces(int);
  void heapify(int);
  int remove();
  void printList();
};


