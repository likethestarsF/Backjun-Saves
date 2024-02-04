// 240204 3 #2775
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void ascendFloor(vector<int> &floor) {
  vector<int> copyed = floor;
  for (int i = 0; i < floor.size(); i++) {
    for (int j = 0; j < i; j++)
      floor[i] += copyed[j];
  }
}

void body() {
  // input
  int t;
  cin >> t;
  while (t--) {
    short k, n;
    int manNum = 0;
    cin >> k >> n;

    //  process
    // easy case: room number 1.
    if (n == 1) {
      manNum = n;
    } else {
      // initialize floor 0. starts at index 0;
      vector<int> floor(n);
      for (int i = 0; i < n; i++) {
        floor[i] = i + 1;
      }
      // ascend k-1 times. then we arrive at floor k-1.
      for (int i = 0; i < k - 1; i++)
        ascendFloor(floor);

      // find the sum of floor k-1. that is the answer.
      for (const auto &elem : floor)
        manNum += elem;
    }

    // output
    cout << manNum << '\n';
  }
}

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  body();
}