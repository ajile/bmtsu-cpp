#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

class RecordInfo {
  public:
  virtual void info() {
    cout << "# info";
  }
};

class Record: public RecordInfo {
  int integer;
  float real;
  public:
    Record (int, float=1);
    int getInteger() { return integer; };
    float getReal() { return real; };
    void info() {
      RecordInfo::info();
      cout << " from Record: ";
      cout << "integer:";
      cout << getInteger();
      cout << "; real:";
      cout << getReal();
      cout << endl;
    };
};

Record::Record(int a, float o) {
  integer = a;
  real = o;
}



class RecordArray: public RecordInfo {
  Record** members;
  int amount;
  public:
    RecordArray (int);
    void info();
    int getRealSize();
    int getMax();
    void sort();
};

RecordArray::RecordArray(int n) {
  amount = n;
  members = new Record*[n];
  for (int i = 0; i < n; ++i) {
    // An integer part of each record is set for sort demo purposes.
    members[i] = new Record(sin(i+1) * 10, i * .5);
  }
}

void RecordArray::info( ) {
  RecordInfo::info();
  cout << " from RecordArray" << endl;
  cout << "## Records: " << endl;
  for (int i = 0; i < amount; ++i) {
    cout << "   Record ";
    cout << i << ". ";
    members[i] -> info();
    /* cout << "integer:"; */
    /* cout << members[i] -> getInteger(); */
    /* cout << "; real:"; */
    /* cout << members[i] -> getReal(); */
    /* cout << endl; */
  }
}

int RecordArray::getRealSize( ) {
  // @todo
  return amount;
}

int RecordArray::getMax( ) {
  int max = 0;
  for (int i = 0; i < getRealSize( ); ++i) {
    if (members[i] -> getInteger() % 2 == 0 && members[i] -> getInteger() > max) {
      max = members[i] -> getInteger();
    }
  }
  return max;
}

void RecordArray::sort( ) {

  // This pointer help us to swap the element in the array
  Record* extraRecord;

  cout << "# Sorting elements in the array" << endl;

  // Bubble sorting
  for (int i = 0; i < getRealSize( ); ++i) {
    for (int j = 0; j < getRealSize( ) - 1; ++j) {
      /* cout << i << "x" << j << ": "; */
      /* cout << members[j] -> getInteger(); */
      /* cout << " x "; */
      /* cout << members[j + 1] -> getInteger(); */
      /* cout << " === "; */
      if (members[j] -> getInteger() < members[j + 1] -> getInteger()) {
        /* cout << "swap"; */
        extraRecord = members[j+1];
        members[j+1] = members[j];
        members[j] = extraRecord;
      }
      /* cout << endl; */
    }
  }

}

int main(int argc, char* argv[]) {

  // Declaring link element members of a RecordArray class
  RecordArray *members;

  // Creating one
  members = new RecordArray(10);

  // Showing the max found element in `members`
  cout << "# The object has " << (*members).getRealSize() << " elements" << endl;

  // Printing element's details
  (*members).info();

  // Showing the max found element in `members`
  cout << "# A max odd integer element: " << (*members).getMax() << endl;

  cout << endl;

  // Sorting records in RecordArray object
  (*members).sort();

  cout << endl;

   // Printing element's details again
  (*members).info();
 
  return 0;
}

