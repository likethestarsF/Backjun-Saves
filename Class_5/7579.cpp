// 240923 1 #7579
// Class 5
// 01:20
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define INF 2e9
using namespace std;

class MY {
  int appNum, targetMemory;
  vector<int> memory;
  vector<int> cost;

  /** Knapsack Problem
   * dpTable[idx][cost] = maxMemory, when idx app is selected.
   * cost is the same with currently secured cost.
   * dp[i][cost] = max(dp[i-1][cost], dp[i-1][cost - cost[i]] + memory[i])
   */
  int knapsack() {
    int minCost = INF;
    vector<vector<int>> dpTable(appNum + 1, vector<int>(10001, -1));

    for (int idxCost = 0; idxCost <= 10000; idxCost++) {
      dpTable[0][idxCost] = 0;
    }

    for (int i = 1; i <= appNum; i++)
      for (int idxCost = 0; idxCost <= 10000; idxCost++) {
        if (idxCost - cost[i] < 0)
          dpTable[i][idxCost] = dpTable[i - 1][idxCost];
        else
          dpTable[i][idxCost] =
              max(dpTable[i - 1][idxCost],
                  dpTable[i - 1][idxCost - cost[i]] + memory[i]);

        if (dpTable[i][idxCost] >= targetMemory)
          return minCost = idxCost;
      }

    return minCost; // error
  }

public:
  MY() {
    /* Input */
    cin >> appNum >> targetMemory; // [,100], [,1e7]
    memory.resize(appNum + 1);
    cost.resize(appNum + 1);

    for (int i = 0; i < appNum; i++)
      cin >> memory[i + 1]; // [,1e7]
    for (int i = 0; i < appNum; i++)
      cin >> cost[i + 1]; // [0 ,100]
  }

  void body() { cout << knapsack(); }
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
