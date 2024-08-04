// 240804 5 #11053
// Class 4
// 02:30
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {
  int lenOfSeq;
  vector<int> seq;
  vector<int> DP;

  int max(const vector<int> &arr) {
    int result = 0;
    for (const auto &i : arr)
      result = std::max(result, i);
    return result;
  }

public:
  void body() {
    // # input
    cin >> lenOfSeq; // [1, 1000]
    seq.resize(lenOfSeq);
    DP.resize(lenOfSeq);
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

    // ## 2nd Trial
    // DP[i] must contain ith elem. So, DP_big isn't needed.
    // So, The max is not the last. It is one of the DP[i].

    // init the first value
    DP[0] = 1;
    for (int i = 1; i < lenOfSeq; i++) {
      // init a default
      DP[i] = 1;

      // Compare with the entire previous DPs
      for (int j = i - 1; j >= 0; j--) {
        if (seq[i] > seq[j])
          DP[i] = std::max(DP[i], DP[j] + 1);
      }
    }
    // Select the maximum
    cout << my::max(DP);
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