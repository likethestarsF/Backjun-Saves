// 241002 1 #10775
// Class 5
// 00:30
#include <algorithm>
#include <iostream>
#include <vector>
// #define MAX 2147483647
// #define ll long long
using namespace std;

class MY {
  int gateNum, planeNum;
  vector<int> gate;

public:
  // MY() {}

  void body() {
    /* Input */
    cin >> gateNum >> planeNum; // [,1e5]

    gate.resize(planeNum);
    for (int i = 0; i < planeNum; i++) {
      cin >> gate[i];
    }

    /** Main
     * 1. Base on input, Dock at most bigger case, sequentially.
     * 2. Save docked place by isDocked.
     * 3. Find the empty place to dock in the reverse-order.
     * * when we can't find empty gate, Terminate the code.

     * O(N^2), Guess it causes the timeout...
     */

    int maxDocked = 0;
    vector<bool> isDocked(gateNum + 1, false);
    isDocked[0] = true;

    for (int i = 0; i < planeNum; i++) {
      int idx = gate[i];
      while (idx > 0) {
        if (!isDocked[idx]) {
          isDocked[idx] = true;
          maxDocked++;
          break;
        }

        idx--;
      }

      if (idx == 0)
        break;
    }

    cout << maxDocked;
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  MY my;
  my.body();
}
