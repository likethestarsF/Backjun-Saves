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
  vector<int> DP = {};

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
    // DP[i] = k : the maximum len of a seq to ith number is k.
    // if (seq[i] > seq[i-1]), DP[i] = DP[i-1] + 1;
    // else if (seq[i] > seq[i-1]) DP[i] = DP[i-2] + 1; and so on.

    for (int i = 0; i < lenOfSeq; i++) {
      // init the default value
      DP[i] = 1;

      // Compare with the previous DPs
      for (int j = i - 1; j >= 0; j--) {
        if (seq[i] > seq[j]) {
          DP[i] = DP[j] + 1;
          break;
        }
      }

      // Select the maximum
      DP[i] = max(DP[i], DP[i - 1]);
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