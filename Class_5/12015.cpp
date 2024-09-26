// 240926 1 #12015
// Class 5
// 00:50
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 1e7
// #define MAX 2147483647
// #define ll long long
using namespace std;

class MY {
  int arrSize;
  vector<int> arr;

public:
  MY() {
    /* Input */
    cin >> arrSize; // [,1e6]
    arr.resize(arrSize);
    for (int i = 0; i < arrSize; i++)
      cin >> arr[i]; // [,1e6]
  }

  void body() {
    /** LIS problem, DP
     * I. O(N^2)
     * 1. dp[i] = max(dp[0~i-1] + 1)

     * II. O(NlogN)
     * 1. dp[0[[i] = max length of LIS
     * 2. dp[1][i] = end number of the (i+1)-length seqeunce
     */

    vector<vector<int>> dpTable(2, vector<int>(arrSize + 2, MAX));
    dpTable[0][0] = 0;
    dpTable[1][0] = 0;

    for (int i = 1; i <= arrSize; i++) {
      // idx of it that is bigger than or equal to arr[i] : 0 ~ i+1th
      const int idx = lower_bound(dpTable[1].begin(),
                                  dpTable[1].begin() + i + 1, arr[i - 1]) -
                      dpTable[1].begin();

      dpTable[0][i] = idx; // there must be idx-1 length in front of (i)th
      dpTable[1][idx] = min(dpTable[1][idx], arr[i - 1]);
    }

    // find Maximum;
    const int globalMax =
        lower_bound(dpTable[1].begin(), dpTable[1].end(), MAX) -
        dpTable[1].begin();
    cout << globalMax - 1;
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
