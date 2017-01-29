#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class NodeClass {
protected:
  void* value;
public:
  NodeClass * prev;
  bool is_number = true;
  NodeClass(bool num, void* v) {
    is_number = num;
    value = v;
  }
  void * get() { return value; }
};

class FacadeClass {
protected:
  NodeClass * latest = NULL;
public:
  void add(int v) {
    cout << "# Creating new node for number " << v << endl;
    int * vc = (int*)malloc(sizeof(int));
    *vc = v;
    NodeClass * node = new NodeClass(true, vc);
    if (latest != NULL)
      node -> prev = latest;
    latest = node;
  }
  void add(std::string v) {
    cout << "# Creating new node for string " << v << endl;
    std::string * vc = (std::string*)malloc(sizeof(std::string));
    *vc = v;
    NodeClass * node = new NodeClass(false, vc);
    if (latest != NULL)
      node -> prev = latest;
    latest = node;
  }
  void remove(int num) {
    cout << "# Removing number " << num << endl;
    NodeClass * current = latest;
    NodeClass * visited = NULL;
    while(current != NULL) {
      if (!current -> is_number) {
        current = current -> prev;
        continue;
      }

      int v = *(int*)(current -> get());

      if (v == num) {
        if (visited)
          visited -> prev = current -> prev;
        current = current -> prev;
        continue;
      }

      visited = current;
      current = current -> prev;
    }
  }
  void print() {
    cout << "# Printing" << endl;
    NodeClass * current = latest;
    while(current != NULL) {
      if (current -> is_number) {
        cout << "Integer: " << *(int*)(current -> get()) << endl;
      } else {
        cout << "String: " << *(std::string*)(current -> get()) << endl;
      }
      current = current -> prev;
    }
  }
};

class BiggestFacadeClass: public FacadeClass {
public:
  NodeClass * biggest() {
    NodeClass * current = latest;
    NodeClass * biggest = current;
    int max = 0;
    while(current != NULL) {
      int s = 0;
      if (current -> is_number) {
        int v = *(int*)(current -> get());
        while (v != 0) { v /= 10; s++; }
      } else {
        std::string v = *(std::string*)(current -> get());
        s = v.size();
      }

      if (s > max) {
        max = s;
        biggest = current;
      }
      current = current -> prev;
    }
    return biggest;
  }
};



int main(int argc, char* argv[]) {
  BiggestFacadeClass bfc;
  bfc.add(1);
  bfc.add(2);
  bfc.add(3);
  bfc.add(4);
  bfc.add(5);
  bfc.add("adsgasdg");
  bfc.add("hello");
  bfc.add(123);
  bfc.add("world");
  bfc.print();

  NodeClass * biggest = bfc.biggest();
  if (biggest -> is_number) {
    cout << "The biggest is number: " << *(int*)bfc.biggest() -> get() << endl;
  } else {
    cout << "The biggest is string: " << *(std::string*)bfc.biggest() -> get() << endl;
  }
  return 0;
}
