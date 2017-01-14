#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>


using namespace std;

int main(int argc, char* argv[]) {

  if (argc < 3) {
    cout << "You should pass path to file so: " << argv[0] << " ./F.txt ./G.txt" << endl;
    return 1;
  }

  ifstream f;
  f.open(argv[1], ios::in | ios::out);

  fstream g;
  g.open(argv[2], ios::in | ios::out);

  string line;

  vector<string> lines;

  while (getline(f, line)) {
    reverse(line.begin(), line.end());
    lines.push_back(line + "\n");
    // cout << line;
  }

  for (int i = lines.size(); i >= 0; --i)
  {
    cout << lines[i];
    g << lines[i];
  }

  g.close();
  f.close();

  return 0;
}
