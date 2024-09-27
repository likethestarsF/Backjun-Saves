// 240927 1 #9252
// Class 5
// 01:00
#include <algorithm>
#include <iostream>
#include <vector>
// #define MAX 2147483647
// #define ll long long
using namespace std;

class MY {

public:
  MY() {}

  void body() {
    /* Input */
    string str1, str2;
    cin >> str1 >> str2; // size:[,1000]

    /** LCS: length & subsequence
     * 1. if(str1[i] == str2[j]), dp[i][j] = dp[i-1][j-1] + 1
     * * length(ABC, BCC) = length(AB, BC) + 1; C is common.
     * 2. else, dp[i][j] = max(dp[i-1][j], dp[i][j-1])
     * * length(ABC, BCD) = max((legth(ABC, BC), length(AB, BCD)))

     * - Find the Subsequence
     * 3. Start from end of dp, length X. Check nearby [-1][], [][-1]
     * 4. if dp[][] == dp[-1][] (OR dp[][-1]), move to dp[-1][]
     * 5. if not, answer[--X] = str1[][]
     * 6. Repeat this 'til X becomes 1

     * Beware:
     * str is 0-index style, dpTable is 1-index style
     */

    // [0] is empty; size() + 1
    vector<vector<int>> dpTable(str1.size() + 1,
                                vector<int>(str2.size() + 1, 0));
    // 1, 2.
    for (int idx1 = 1; idx1 <= str1.size(); idx1++)
      for (int idx2 = 1; idx2 <= str2.size(); idx2++) {
        if (str1[idx1 - 1] == str2[idx2 - 1]) // 1.
          dpTable[idx1][idx2] = dpTable[idx1 - 1][idx2 - 1] + 1;

        else
          dpTable[idx1][idx2] =
              max(dpTable[idx1 - 1][idx2], dpTable[idx1][idx2 - 1]);
      }

    // 3.
    int row = str1.size(), col = str2.size();
    int index = dpTable[row][col];
    string answer(index, ' ');

    // 6.
    while (index > 0) {
      // 4.
      if (dpTable[row][col] == dpTable[row - 1][col]) {
        row--;
        continue;
      }
      if (dpTable[row][col] == dpTable[row][col - 1]) {
        col--;
        continue;
      }

      // 5.
      answer[--index] = str1[row - 1];
      row--, col--;
    }

    /* Output */
    cout << dpTable[str1.size()][str2.size()] << '\n';
    cout << answer;
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
