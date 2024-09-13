// 240913 2 #17404
// Class 5
// 00:15
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

   * color : 012121..., 102020..., 21010...
   * color of [0] is used only at the [0]
   * remain 2 colors are used repeatedly. 1212 or 2121
   -> 3C1 * 2! = total 6 cases
   */

public:
  void body() {
    /* INPUT */
    cin >> houseN; // [2, 1000]
    cost.resize(houseN, vector<int>(3));
    for (int i = 0; i < houseN; i++)
      cin >> cost[i][0] >> cost[i][1] >> cost[i][2]; // [1, 1000]

    vector<int> sumOfCost(6, 0); // maxSum = 1000 * 1000 < 2^30
    // 6cases : {012, 021, 102, 120, 201, 210}, not perfectly correct
    const vector<vector<int>> order = {{1, 2}, {2, 1}, {0, 2},
                                       {2, 0}, {0, 1}, {1, 0}};
    // init.
    sumOfCost[0] = cost[0][0];
    sumOfCost[1] = cost[0][0];
    sumOfCost[2] = cost[0][1];
    sumOfCost[3] = cost[0][1];
    sumOfCost[4] = cost[0][2];
    sumOfCost[5] = cost[0][2];

    for (int i = 1; i < houseN; i++)
      for (int j = 0; j < 6; j++) {
        sumOfCost[j] += cost[i][order[j][i % 2]];
      }

    // Find Min
    int min = MAX;
    for (const auto &elem : sumOfCost)
      min = std::min(min, elem);
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