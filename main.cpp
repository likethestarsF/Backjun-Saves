// 240729 1 #30804
// Class 3
// 00:
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
    while (iEnd != nMax - 1) {
      const int type1 = tanghuru[iStart];
      int type2 = type1;
      for (int index = iStart; index < nMax; index++) {
        if (tanghuru[index] == type1)
          continue;
        if (tanghuru[index] == type2)
          continue;

        // update type2 only 1 time
        if (type2 == type1) {
          if (tanghuru[index] != type1)
            type2 = tanghuru[index];
        }

        // save last fruit's index as iEnd
        else {
          iEnd = index - 1;
          break;
        }

        if (index == nMax - 1)
          iEnd = index;
      }

      // calc. the number of fruits and update max
      max = (max > iEnd - iStart + 1) ? max : iEnd - iStart + 1;
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