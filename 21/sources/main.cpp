#include <iostream>

using namespace std;

int main(void) {

  // Matrix dimentions
  const unsigned int DIMENSION = 4;
 
  // i, j - The counter cycles' variables
  // The p - is a temporary variable contains position of
  //           the biggest value in iterating column.
  unsigned int i, j, p;

  // The biggest value is found in column on iteration.
  // The tmp - is a temporary variable helps to swap the
  //           biggest value in column and diagonal value.
  float biggest, tmp;

  // The matrix
  float matrix[DIMENSION][DIMENSION] = {
    {32, 12, 65, 23},
    {61, 31, 94, 71},
    {45, 37, 82, 67},
    {54, 86, 63, 10}
  };

  cout << endl << "The origin matrix:" << endl;

  // Show user the origin matrix that we will be changed in
  // accordance with the exercise conditions.
  for (i = 0; i < DIMENSION; i++) {
    for (j = 0; j < DIMENSION; j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }

  cout << endl;

  for (i = 0; i < DIMENSION; i++) {
    // Resetting the biggest variable before iterating over
    // the next one column.
    biggest = 0;

    // Iterating over another one column to find the biggest
    // element in it.
    for (j = 0; j < DIMENSION; j++)
      if (matrix[j][i] > biggest) {
        biggest = matrix[j][i];

        // Memorizing position of the biggest element. It
        // help us to swap the biggest value with a diagonal
        // element.
        p = j;
      }

    cout << "Column " << i << ". The biggest value is " <<
      biggest << ", found on " << p << " place." <<
      "\nIt should be swapped with diagonal element on " <<
      4 - i - 1 << " place." << endl;
    cout << endl;

    // Swapping biggest element with element in column
    // expected to be diagonal in the matrix.
    tmp = matrix[DIMENSION - 1 - i][i];
    matrix[DIMENSION - 1 - i][i] = matrix[p][i];
    matrix[p][i] = tmp;
  }

  cout << endl << "The result matrix:" << endl;

  // Show user the result matrix, in which the biggest
  // elements in its columns were swapped with elements
  // layed on the main matrix diagonal.
  for (i = 0; i < DIMENSION; i++) {
    for (j = 0; j < DIMENSION; j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }

  return 0;
}

