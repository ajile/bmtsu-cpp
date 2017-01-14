#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

bool isLetter(char symbol) {
  int charCode = (int)symbol;
  return (charCode >= 65 && charCode <= 90) || (charCode >= 97 && charCode <= 122);
}
bool isNumber(char symbol) {
  int charCode = (int)symbol;
  return charCode >= 48 && charCode <= 57;
}
bool isSign(char symbol) {
  int charCode = (int)symbol;
  return charCode == 42 || charCode == 43 || charCode == 45;
}

std::vector<int> getGroups(string str) {

  // The current group in the cycle.
  // 0 - unknown, 1 - letters, 2 - numbers, 3 - signs
  unsigned int groupNumber = 0;

  unsigned int letterAmount = 0;
  unsigned int numberAmount = 0;
  unsigned int signAmount = 0;

  // Iterating over letters in sentence
  for (int i = 0; i <= str.length(); ++i) {

    // The letter code which help us to determine its group
    int charCode = (int)str[i];

    // It's a space
    if (charCode == 32) {
      groupNumber = 0;
      continue;
    }

    // It's a latter
    if (isLetter(str[i])) {
      (groupNumber != 1) && (letterAmount++);
      groupNumber = 1;
    }

    // It's a number
    if (isNumber(str[i])) {
      (groupNumber != 2) && (numberAmount++);
      groupNumber = 2;
    }

    // It's one of '+', '-' or '*'
    if (isSign(str[i])) {
      (groupNumber != 3) && (signAmount++);
      groupNumber = 3;
    }

  }

  std::vector<int> result;
  result.push_back(letterAmount);
  result.push_back(numberAmount);
  result.push_back(signAmount);

  return result;
}

int main(void) {

  string sentencies[] = {
    "Do not worry about your +-+----+++--+ difficulties3123in mathematics *-+, I assure you that mine are greater.",
    "Mathematics is1222the tool+specially suited 32886 for dealing with abstract concepts of any kind",
    "*-+If*-++-you*-+ask*-+mathematicians*-+333what*-+they*-+do*-+"
  };

  // Amount of the groups found in sentence (it's a temporary
  // variable)
  std::vector<int> amounts;

  // The sums of group amount in every sentence for each type
  // of group (letters, numbers and signs)
  int sums[] = { 0, 0, 0 };

  // Amount of sentencies which should be processed
  int const amount = sizeof(sentencies) / sizeof(*sentencies);

  cout << "# Origin sentencies:" << endl;

  // Iterating over sentencies
  for (int i = 0; i < amount; ++i) {

    // Getting group amounts for current sentence
    amounts = getGroups(sentencies[i]);

    // Showing metrics to user
    cout << "  " << i << ". " << sentencies[i] << endl;
    cout << "    Letters: " << amounts[0] << " groups" << endl;
    cout << "    Numbers: " << amounts[1] << " groups" << endl;
    cout << "    Signs: " << amounts[2] << " groups" << endl;
    cout << endl;

    // Calculating sums
    sums[0] += amounts[0];
    sums[1] += amounts[1];
    sums[2] += amounts[2];
  }

  cout << endl;

  // Whether sign group amount greater than letter group
  // amount. If it's so - do nothing just quiting. Otherwise
  // replacing all sign groups to `123`.
  if (sums[0] < sums[2]) {
    cout << "Sign group amount greater then letter group amount. ";
    cout << "Do nothing in this case.";
    return 0;
  }

  cout << "Letter group amount is greater than sign group amount. ";
  cout << "Iterating over all sentencies and replacing all sign groups ";
  cout << "to 123 in accondance with task.";
  cout << endl;
  cout << endl;


  // Whether in the sign group.
  bool inGroup = false;

  // The position of the first found sign in a group. This var
  // set when inGroup variable becomes true.
  int lastBegin = 0;

  // ...over sentencies
  for (int i = 0; i < amount; ++i) {

    // ...over chars
    for (int j = 0; j <= sentencies[i].length(); ++j) {

      if (isSign(sentencies[i][j])) {
        if (!inGroup) {
          // Memorizing position when first char of the sign group
          // has been met.
          lastBegin = j;
        }
        inGroup = true;
      } else if (inGroup) {
        // Replacing sentecies' chunk from position where the sign
        // group began to current position.
        sentencies[i].replace(lastBegin, j-lastBegin,"123");
        inGroup = false;
      }
    }

  }

  cout << endl;

  cout << "# Resultee sentencies:" << endl;

  // Showing metrics to user
  for (int i = 0; i < amount; ++i)
    cout << "  " << i << ". " << sentencies[i] << endl;

  return 0;
}
