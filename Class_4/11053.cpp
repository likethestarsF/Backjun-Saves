// 240804 5 #11053
// Class 4
// 00:
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {
  int lenOfSeq;
  vector<int> seq;
  vector<int> DP;
  vector<int> DP_big;

public:
  void body() {
    // # input
    cin >> lenOfSeq; // [1, 1000]
    seq.resize(lenOfSeq);
    DP.resize(lenOfSeq);
    DP_big.resize(lenOfSeq);

    for (int i = 0; i < lenOfSeq; i++)
      cin >> seq[i]; // [1, 1000]

    // ## Process
    // Find the longest Leng of the increasing partial seq.
    // update the partial seq step by step.
    // DP[i] = k : k is the max len of a seq to ith number.
    // DP_big[i] = l : l is a biggest num of a seq for DP[i]
    // if (seq[i] > the biggest value of DP[i-1]) DP[i] = DP[i-1] + 1;
    // else if (seq[i] > the biggest value of DP[i-2]) DP[i] = DP[i-2] + 1;
    // and so on.

    // init the first value.
    DP[0] = 1;
    DP_big[0] = seq[0];

    for (int i = 1; i < lenOfSeq; i++) {
      // init the default value
      DP[i] = 1, DP_big[i] = seq[i];

      // Compare with the previous DPs
      for (int j = i - 1; j >= 0; j--) {
        if (seq[i] > DP_big[j]) {
          DP[i] = DP[j] + 1;
          break;
        }
      }

      // Select the maximum
      if (DP[i] == DP[i - 1])
        DP_big[i] = min(DP_big[i], DP_big[i - 1]);
      else if (DP[i] < DP[i - 1]) {
        DP[i] = DP[i - 1];
        DP_big[i] = DP_big[i - 1];
      }
    }
    cout << DP.back();
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