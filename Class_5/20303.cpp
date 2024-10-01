// 241001 1 #20303
// Class 5
// 01:20
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
// #define MAX 2147483647
// #define ll long long
using namespace std;

class MY {
  int childNum, relationNum, childMin;
  vector<int> candy;
  vector<vector<int>> graph;

  pair<int, int> BFS(const int &start, vector<bool> &isVisited) {
    int childCnt = 0, candyCnt = 0;

    queue<int> q;
    q.push(start);
    isVisited[start] = true;

    while (!q.empty()) {
      int cur = q.front();
      candyCnt += candy[cur];
      childCnt++;
      q.pop();

      for (const int &next : graph[cur]) {
        if (!isVisited[next]) {
          q.push(next);
          isVisited[next] = true;
        }
      }
    }

    return {childCnt, candyCnt};
  }

  vector<pair<int, int>> findGroup() {
    vector<pair<int, int>> result = {};

    vector<bool> isVisited(childNum, false);
    for (int i = 0; i < childNum; i++) {
      if (isVisited[i])
        continue;

      result.push_back(BFS(i, isVisited));
    }

    return result;
  }

public:
  // MY() {}

  void body() {
    /* Input */
    cin >> childNum >> relationNum >> childMin; // [,3e4], [0,1e6], [,3000]

    candy.resize(childNum);
    for (int i = 0; i < childNum; i++)
      cin >> candy[i]; // [,1e4]

    graph.resize(childNum, vector<int>(childNum));
    for (int i = 0; i < relationNum; i++) {
      int first, second;
      cin >> first >> second;
      first--, second--;
      graph[first].push_back(second);
      graph[second].push_back(first);
    }

    /** Graph -> Knapsack Problem
     * 1. Transfer the num of individual candy into that of a group
     * * groupInfo : {Child Number, Candy Number}

     * 2. Find maximum Sum of candies
     * * DP[i][j, childMin] = Maximum candyNumber.
     * 2-1. If(j(occupying number) < ith child's num),
     * * DP[i][j] = DP[i-1][j]; ith can't be selected, use previous max.
     * 2-2. Else, DP[i][j] = max(Previous, Suppose ith is selected)
     * * Max with ith selected: dptable[i-1][j-ith's childNum] + ith's candyNum
     * * Max of (i-1)th that has capacity to select ith + ith's candyNum

     * Use a pair of 1D dpTables instead of 2D dpTable because of OOM.
     */

    // 1.
    const vector<pair<int, int>> candyGroup = findGroup();

    // 2.
    vector<int> dpTablePrev(childMin, 0), dpTable(childMin, 0);

    for (int i = 0; i < candyGroup.size(); i++) {
      for (int num = 0; num < childMin; num++) {
        // 2-1.
        if (candyGroup[i].first > num)
          dpTable[num] = dpTablePrev[num];

        // 2-2.
        else {
          dpTable[num] =
              max(dpTablePrev[num], dpTablePrev[num - candyGroup[i].first] +
                                        candyGroup[i].second);
        }
      }

      // update dpTable
      dpTablePrev = dpTable;
    }

    /* Output */
    cout << dpTable[childMin - 1];
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