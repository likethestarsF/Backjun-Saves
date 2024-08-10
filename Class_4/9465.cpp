// 240810 3 #9465
// Class 4
// 00:40
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {
  int testSize;

  int FindMax() {
    // #input
    int n;
    cin >> n; // [1, 100000]
    vector<vector<int>> sticker = vector<vector<int>>(2, vector<int>(n));
    for (int i = 0; i < n; i++)
      cin >> sticker[0][i]; // [0, 100]
    for (int i = 0; i < n; i++)
      cin >> sticker[1][i];

    // init
    vector<vector<int>> DP(3, vector<int>(n, 0));
    DP[0][0] = 0;
    DP[1][0] = sticker[0][0];
    DP[2][0] = sticker[1][0];

    /*
     DP[0][i] = max(DP[0][i-1], DP[1][i-1], DP[2][i-1])
      : max case when selc. none in ith col.
     DP[1][i] = max(DP[0][i-1], DP[2][i-1]) + sticker[1][i]
      : ,, selc. 1th row in ith col.
     DP[2][i] = max(DP[0][i-1], DP[1][i-1]) + sticker[2][i]
      : ,, selc. 2th row in ith col.
    */
    for (int i = 1; i < n; i++) {
      DP[0][i] = max(max(DP[0][i - 1], DP[1][i - 1]), DP[2][i - 1]);
      DP[1][i] = max(DP[0][i - 1], DP[2][i - 1]) + sticker[0][i];
      DP[2][i] = max(DP[0][i - 1], DP[1][i - 1]) + sticker[1][i];
    }

    int result = max(max(DP[0][n - 1], DP[1][n - 1]), DP[2][n - 1]);
    return result;
  }

public:
  void body() {
    cin >> testSize;

    while (testSize--) {
      int max = FindMax();
      cout << max << '\n';
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