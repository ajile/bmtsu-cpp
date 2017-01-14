#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Node {
  float value;
  Node* next = NULL;
  Node* prev = NULL;
};

/**
 * @example
 * ➜ ./result/main
 * # Input numbers (at least 2)
 *   1.726 8.312 9.245 3.111 4.263 6.246 8.123
 * # Iterating over the list
 *   Pointer I: 1.726  |  Pointer II: 8.123
 *   Pointer I: 8.312  |  Pointer II: 6.246
 *   Pointer I: 9.245  |  Pointer II: 4.263
 *   Pointer I: 3.111  |  Pointer II: 3.111
 *   Pointer I: 4.263  |  Pointer II: 9.245
 *   Pointer I: 6.246  |  Pointer II: 8.312
 *   Pointer I: 8.123  |  Pointer II: 1.726
 * # The result of the multiplications:
 *   14.0203
 *   51.9168
 *   39.4114
 *   9.67832
 *   39.4114
 *   51.9168
 *   14.0203
 */
int main(void) {

  // Vector where we'll put all numbers found in the given string.
  // Internally, vectors use a dynamically allocated array to store
  // their elements. This array may need to be reallocated in order
  // to grow in size when new elements are inserted, which implies
  // allocating a new array and moving all elements to it. This is
  // a relatively expensive task in terms of processing time, and thus,
  // vectors do not reallocate each time an element is added to the container.
  std::vector<float> numbers;

  cout << "# Input numbers (at least 2)" << endl;
  cout << "  ";

  // Reading console
  // @example: 1.726 8.312 9.245 3.111 4.263 6.246 8.123
  std::string input;
  std::getline(std::cin, input);

  // Creating a stream to operate with
  std::istringstream ss(input);

  // Contains currently getting number from the stream
  std::string currentNumber;

  // Iterating over numbers in the line and putting each of them
  // into the vector.
  while (std::getline(ss, currentNumber, ' '))
    numbers.push_back(atof(currentNumber.c_str()));

  if (numbers.size() < 2) {
    cout << "Please input at least 2 values." << endl;
    return 1;
  }

  // Array of the result of multiplication
  float results[numbers.size()];

  // Variable used for indexing elements in result array 
  unsigned int i = 0;

  // A temporary variable is needed by cycle below to assemble
  // the list structure.
  Node* prev = NULL;

  // The list itself.
  Node* node;

  // Pointers to first and last elements in the list.
  Node* pointer1 = NULL;
  Node* pointer2 = NULL;

  // Creating (filling) a two-way list structure which will
  // be used further for multiplication opposite items in it.
  for (; i < numbers.size(); ++i) {

    // Creating the next node of the list
    node = new Node();

    // Setting up the it's value
    node -> value = numbers[i];

    // Pointing to the first item in the list
    pointer1 == NULL && (pointer1 = node);

    // If previous element already exists, setting its `next`
    // property to just-created node.
    prev != NULL && (prev -> next = node);

    // Pointing prev property of just-created node to previous
    // node. If the previous node does's exist, NULL value will
    // be set instead.
    node -> prev = prev;

    // The node was created earlier becomes prev for next iteration
    prev = node;

    // Making just-created node the last one.
    pointer2 = node;
  }

  i = 0;

  cout << "# Iterating over the list" << endl;

  // Until `pointer1` AND `pointer2` exist - repeating the cycle's
  // body. The multiplication impossible without one of them.
  while (pointer1 && pointer2) {

    // Printing intermediate result for debugging
    cout << "  ";
    cout << "Pointer I: " << pointer1 -> value;
    cout << "\t|\t";
    cout << "Pointer II: " << pointer2 -> value;
    cout << endl;

    // Putting calculation into the array in accordance
    // with task
    results[i++] = pointer1 -> value * pointer2 -> value;

    // Shifting pointers
    pointer1 = pointer1 -> next;
    pointer2 = pointer2 -> prev;
  }


  cout << "# The result of the multiplications:" << endl;

  for (int k = 0; k < i; ++k)
  {
    cout << "  ";
    cout << results[k] << endl;
  }

  return 0;
}
