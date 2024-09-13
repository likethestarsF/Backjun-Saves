// 240913 2 #17404
// Class 5
// 00:35
#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 10000000
using namespace std;

class my {
  int houseN;
  vector<vector<int>> cost; // cost[house][RGB]
                            // [RGB] = 0:R, 1:G, 2:B

  /** RULE of coloring
   * 1. color[0] != color[1] && color[N]
   * 2. color[n] != color[n-1] && color[0]
   * 3. color[i] != color[i-1] && color[i+1], i>=1

   * DP[i][x] : the min value, selecting color in the ith house
   * DP[i][x] = min(DP[i-1][y], DP[i-1][z]) + cost[i][x]
   * do we have to define DP[0] manually?
   * fix the 0st manually elem, update last elems up to houseSize-2.

   * Bottom-Up.
   * starting, 0 1 2
   */

public:
  void body() {
    /* INPUT */
    cin >> houseN; // [2, 1000]
    cost.resize(houseN, vector<int>(3));
    for (int i = 0; i < houseN; i++)
      cin >> cost[i][0] >> cost[i][1] >> cost[i][2]; // [1, 1000]

    vector<vector<int>> DP(houseN, vector<int>(3, 0));
    for (int i = 0; i < 3; i++)
      DP[0][i] = cost[0][i];

    for (int idxH = 1; idxH < houseN; idxH++)
      for (int idxC = 0; idxC < 3; idxC++) {
        DP[idxH][idxC] =
            min(DP[idxH - 1][(idxC + 1) % 3], DP[idxH - 1][(idxC + 2) % 3]) +
            cost[idxH][idxC];
      }

    // Find Min
    int min = MAX;
    for (const auto &sum : DP[houseN - 1])
      min = std::min(min, sum);
    cout << min;
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