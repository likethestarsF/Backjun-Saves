// 240913 1 #10942
// Class 5
// 00:30
#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 200000
using namespace std;

class my {
  int seqSize, testN;
  vector<int> seq;

  /**
   * Palindrome
   * DP[x][y] is Palindrome, only when
   * DP[x+1][y-1] is Palindrome and seq[x] == seq[y]
   * COND.: x+1 <= y-1 && (x==y || x<y)
   */

  vector<vector<short>> DP; // DP[start][end]
                            // -1 : unchecked, 0 : false, 1 : true
  bool isPalindrome(const int &start, const int &end) {
    // if already checked
    if (DP[start][end] != -1)
      return DP[start][end];

    if (start == end)
      return DP[start][end] = true;

    if (start + 1 == end && seq[start] == seq[end])
      return DP[start][end] = true;

    if (start > end)
      return DP[start][end] = false;

    else /*start < end*/ {
      if (seq[start] != seq[end])
        return DP[start][end] = false;

      else // check [x+1][y-1]
        return DP[start + 1][end - 1] = isPalindrome(start + 1, end - 1);
    }
  }

public:
  void body() {
    /* INPUT */
    cin >> seqSize; // [1, 2000]
    seq.resize(seqSize);
    for (int i = 0; i < seqSize; i++)
      cin >> seq[i]; // [1, 100000]

    DP.resize(seqSize, vector<short>(seqSize, -1));

    cin >> testN;
    while (testN--) {
      int idxS, idxE;
      cin >> idxS >> idxE;
      idxS--, idxE--;
      cout << isPalindrome(idxS, idxE) << '\n';
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