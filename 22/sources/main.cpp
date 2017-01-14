#include <iostream>

using namespace std;

int main(void) {

  unsigned int i, openBrackets = 0;
  int counter = 0;
  bool done = false;

  const char str[] = "Hello it's a string (an array (first of second brackets) of chars (there is no another way to declare a string in c++))";

  // Show user the origin string
  cout << ">> The string: \"" << str << "\"" << endl;

  for (i = 0; i < sizeof(str); i++) {

    // Decrementing counter on close-bracket
    str[i] == ')' && (--counter && (done = true));

    if (openBrackets >= 2 && !done) {
      cout << str[i] << " = " << (void*) &str[i] << endl;
    }

    // Incrementing counter on open-bracket
    str[i] == '(' && (++counter && ++openBrackets);

    // If counter less the 0 that means that the close-bracket
    // has been meen earlier than open-bracket. In this case the
    // algorithm is not working - quiting the cycle.
    if (counter < 0) {
      cout << "Wrong sequence of the brackets" << endl;
      break;
    }

  }

  if (!counter) {
    cout << "Amount of the brackets is correct" << endl;
  } else {
    cout << "Amount of the brackets is NOT correct" << endl;
  }

  return 0;
}

