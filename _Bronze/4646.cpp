// 240726 1 #4646
// Random Marthon 8 C
#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

class my {

public:
  void body() {
    while (true) {
      int n;
      cin >> n;

      if (n == 0)
        break; // EXIT

      // making vector for the table
      vector<int> table;
      table.resize(n);
      for (int i = 0; i < n; i++) {
        cin >> table[i];
      }

      // make 2 index for Sam and Ella
      int Sam_index = 0;
      int Ella_index = n - 1;
      int Sam = table[0];
      int Ella = table[n - 1];

      // added til where they are standing
      while (Sam_index < Ella_index) {
        // Case 0. Breakpoint
        if (Sam_index + 1 == Ella_index) {
          break;
        }

        // Case 1. Sam is bigger than Ella
        if (Sam > Ella) {
          Ella_index--;
          Ella += table[Ella_index];
        }
        // Case 2. Ella is bigger than Sam
        else if (Ella > Sam) {
          Sam_index++;
          Sam += table[Sam_index];
        }
        // Case 3. Sam is equal to Ella
        else {
          Sam_index++;
          Sam += table[Sam_index];
        }
      }

      // output of result
      if (Sam != Ella) {
        cout << "No equal partitioning.\n";
      } else {
        cout << "Sam stops at position " << Sam_index + 1
             << " and Ella stops at position " << Ella_index + 1 << ".\n";
      }
    }
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  my a;
  a.body();
}