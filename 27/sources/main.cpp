#include <iostream>
#include <stdio.h>

using namespace std;

class Angar {
  int area;
  double occupied;
  public:
    Angar (int, float=1);
    float freeArea () { return area * (1-occupied); }
};

Angar::Angar(int a, float o) {
  area = a;
  occupied = o;
}

struct ListNode {
  ListNode* next = NULL;
  Angar* value = NULL;
};

int main(int argc, char* argv[]) {

  float freeArea = 0;

  // Creating store via Array
  Angar rooms[3] { {20,.5},{20,.25},{10,.75} };

  for (int i = 0; i < sizeof(rooms) / sizeof(*rooms); ++i)
    freeArea += rooms[i].freeArea();

  cout << "(array) Free area is " << freeArea << endl;



  freeArea = 0;
  ListNode *room1, *room2, *room3;
  room1 = new ListNode();
  room2 = new ListNode();
  room3 = new ListNode();
  room1 -> value = &rooms[0];
  room2 -> value = &rooms[1];
  room3 -> value = &rooms[2];
  room1 -> next = room2;
  room2 -> next = room3;

  ListNode * room = room1;

  do {
    freeArea += (*(room -> value)).freeArea();
    room = room -> next;
  } while (room);
  cout << "(list)  Free area is " << freeArea << endl;

  return 0;
}
