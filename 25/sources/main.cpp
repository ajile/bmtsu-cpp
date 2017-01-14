#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

using namespace std;

int getSum(int b[], int checkAmount) {

  // The won numbers array
  int a[] = {1111, 1112, 1113, 1114, 1115, 1116};

  // The sum for each of numberss
  int p[] = {1000, 2500, 5000, 10000, 25000, 50000};

  int sum = 0;

  for (int i = 0; i < checkAmount; ++i) {
    cout << "Looking for " << b[i] << ":" << endl;
    for (int j = 0; j < ARRAY_SIZE(a); ++j) {
      cout << "a#" << a[j];
      if (a[j] == b[i]) {
        cout << "- found (sum " << p[j] << ")";
        sum += p[j];
      }
      cout << endl;
    }
  }

  return sum;
}

int main(void) {

  // Array of numbers to calculate
  int b[] = {1111, 1113, 1116};

  cout << "Summa: " << getSum(b, ARRAY_SIZE(b));

  return 0;
}
