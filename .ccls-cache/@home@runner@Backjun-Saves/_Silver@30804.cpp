// 240729 1 #30804
// Class 3
// 01:50
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {
  int nMax;
  vector<int> tanghuru;
  vector<bool> fruitTypes = vector<bool>(10, false); // [0] is not used.

public:
  void body() {
    /*  Input  */
    cin >> nMax; // [1, 200000]
    tanghuru.resize(nMax);
    for (int i = 0; i < nMax; i++) {
      cin >> tanghuru[i]; // [1, 9]
      fruitTypes[tanghuru[i]] = true;
    }

    // Unique case: Types of fruits are less than 3
    int cnt = 0;
    for (const bool i : fruitTypes) {
      if (i == true)
        cnt++;
    }

    if (cnt < 3) {
      cout << nMax;
      return;
    }

    // General case:
    // Use index to make O(1) time complexity in both front and back
    // What It is pointing now are included ones.
    int iStart = 0;
    int iEnd = iStart;
    int max = 0;

    while (iStart != nMax - 1) {
      const int type1 = tanghuru[iStart];
      int type2 = type1;

      bool isBreak = false;
      for (int index = iStart; index < nMax; index++) {
        if (tanghuru[index] != type1 && tanghuru[index] != type2) {
          // update type2 only 1 time
          if (type2 == type1) {
            type2 = tanghuru[index];
          }

          else {
            // save the index of last fruit
            iEnd = index - 1;
            isBreak = true;
            break;
          }
        }
      }

      // calc. the number of fruits and update max
      if (!isBreak)
        iEnd = nMax - 1;

      // check if there are more the same type fruits in front of iStart.
      int extra = 0;
      for (int i = iStart - 1; i > 0; i--) {
        if (tanghuru[i] == type1 || tanghuru[i] == type2)
          extra++;
        else
          break;
      }

      max = (max > iEnd - iStart + 1 + extra) ? max : iEnd - iStart + 1 + extra;

      // update iStart.
      iStart = iEnd;
    }

    /*  Output  */
    cout << max;
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