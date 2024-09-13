// 240913 2 #17404
// Class 5
// 00:50
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
   * DP is changed into prev; don't need to save every stage by DP.

   * do we have to define DP[0] manually?
   * -> fix the 0st manually elem, update last elems
   */
  int findMin(int &startColor) {
    vector<int> prev(3, 0);

    // Coloring 1st, only select 1 color
    for (int i = 0; i < 3; i++) {
      if (i == startColor)
        prev[i] = cost[0][i];
      else
        prev[i] = MAX;
    }

    // Coloring everything, except 1st
    for (int idxH = 1; idxH < houseN; idxH++) {
      vector<int> next(3, 0);
      for (int idxC = 0; idxC < 3; idxC++) {
        next[idxC] =
            min(prev[(idxC + 1) % 3], prev[(idxC + 2) % 3]) + cost[idxH][idxC];
      }
      prev = next;
    }

    // Except the color[0] == color[n] case
    int min = MAX;
    for (int i = 0; i < 3; i++) {
      if (i == startColor)
        continue;
      min = std::min(min, prev[i]);
    }

    return min;
  }

public:
  void body() {
    /* INPUT */
    cin >> houseN; // [2, 1000]
    cost.resize(houseN, vector<int>(3));
    for (int i = 0; i < houseN; i++)
      cin >> cost[i][0] >> cost[i][1] >> cost[i][2]; // [1, 1000]

    int min = MAX;
    for (int i = 0; i < 3; i++)
      min = std::min(min, findMin(i));

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