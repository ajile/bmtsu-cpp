#include <iostream>
#include <cmath>

#define DEBUG 1

int main(void) {

  // Sign of successfull
  bool P = false;

  // The program below iterates over numbers from 0..k
  // range. The n variable is temporary variable for
  // the cycle.
  int n, k = 10, x = 3;

  // Intermediate variable that contain value of sin(n)
  float sin_value;

  for (n = 1; n < k; n++) {

    // Write down sin value into temporary variable
    sin_value = sin(pow(x, n));

    #ifdef DEBUG
    // Show the user intermediate result (for debugging
    // purpose).
    std::cout << "Sin of the x^n (" << x << "^" << n <<
        " equal " << sin_value << std::endl;
    #endif

    // When sin_value variable less the zero, setting P
    // variable true and breaking the cycle.
    if (sin_value < 0) {

      #ifdef DEBUG
      // Signalizing when cycle breaks
      std::cout << "The sin_value became " <<
        "negative" << std::endl;
      #endif

      P = true;
      break;
    }

  }

  // Show the result to user.
  if (P) {
    std::cout << "P is true" << std::endl;
  } else {
    std::cout << "P is false" << std::endl;
  }

  return 0;
}
