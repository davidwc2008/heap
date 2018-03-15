#include "heap.h"

using namespace std;

//constructor
heap::heap() {
  size = 0;
}

//code to add elements to the heap
void heap::add(int to_add) {
  int child = size;
  int parent = (child - 1)/2;
  input[size] = to_add;
  size++;

  while (child != 0 && input[parent] < input[child]) {
    swap(input[child], input[parent]);
    child = parent;
    parent = (child - 1)/2;
  }
}

void heap::printTree(int counter) {
  int row = rows();
  int each_row = 1;
  int a = 0;

  cout << "Printed Tree: " << endl;
  
  for (int i = 0; i < rows(); i++) {
    for (int i = 0; i < pow(2, row) - 1; i++) cout << " ";
    for (int i = 0; i < each_row; i++) {
      if (input[a] && a <= (counter - 1)) {
	cout << input[a];
	a++;
	for (int n = 0; n < ((pow(2, (row+1))-1) - spaces(input[a-1])); n++) cout << " ";
      }
    }
    each_row = 2 * each_row;
    row--;
    cout << endl;
  }
}

//returns the number of rows that the heap should have
int heap::rows() {
  if (size <= 1) return 1;
  if (size > 1 && size <= 3) return 2;
  if (size > 3 && size <= 7) return 3;
  if (size > 7 && size <= 15) return 4;
  if (size > 15 && size <= 31) return 5;
  if (size > 31 && size <= 63) return 6;
  if (size > 63) return 7;
  return 0;
}

//return the number of space that should be removed between each number for printTree
int heap::spaces(int num) {
  if (num >= 10 && num < 100) return 1;
  if (num >= 100 && num < 1000) return 2;
  if (num == 1000) return 3; //can't be bigger than this... that's the requirement
  return 0;
}

void heap::heapify(int root) {
  int left = 2 * root + 1;
  int right = 2 * root + 2;
  int top = root;
  if ((left <= size) && (input[left] > input[top])) {
    top = left;
  }
  if ((right <= size) && (input[right] > input[top])) {
    top = right;
  }
  if (top != root) {
    swap(input[root], input[top]);
    heapify(top);
  }
}

//remove the "nodes" from the heap one at a time
int heap::remove() {
  int toRemove = input[0];
  input[0] = input[size];
  size--;
  heapify(0); //used to re-heapify so we can pluck the highest off
  return toRemove;
}

//print the list from largest to smallest
void heap::printList() {
  cout << "From largest to smallest: " << endl;
  while (size != 0) {
    int i = remove();
    if (size == 0) {
      cout << i << ".";
    } else {
      cout << i << ", ";
    }
  }
  cout << endl << endl; 
}
