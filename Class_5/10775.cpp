// 241002 1 #10775
// Class 5
// 00:
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

    gate.resize(gateNum + 1, 0);
    for (int i = 0; i < planeNum; i++) {
      int input;
      cin >> input;
      gate[input]++;
    }

    /** Main
     * 1. Add plane starting from smaller number.
     * 2. only ith MaxDocked = min(ithPlaneNumber, 'i');
     * 3. Consider the previous.
     * * ith MaxDocked = prevDocked + min('i' - prevDocked, ithPlaneNumber);
     * * = min(ithPlaneNumber + prevDocked, 'i');
     * * -> MaxDocked += min(i-prevDocked, ithPlaneNumber);
     */

    int maxDocked = 0;
    for (int i = 1; i <= gateNum; i++)
      maxDocked += min(i - maxDocked, gate[i]);

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
