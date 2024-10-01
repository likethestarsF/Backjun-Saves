// 241001 1 #20303
// Class 5
// 01:00
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
    vector<pair<int, int>> result = {{0, 0}};

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
     */
    // 1.
    const vector<pair<int, int>> candyGroup = findGroup();

    // 2.
    vector<vector<int>> dpTable(candyGroup.size(), vector<int>(childMin, 0));
    for (int i = 1; i < candyGroup.size(); i++) {
      for (int num = 0; num < childMin; num++) {
        // 2-1.
        if (candyGroup[i].first > num)
          dpTable[i][num] = dpTable[i - 1][num];

        // 2-2.
        else {
          dpTable[i][num] = max(dpTable[i - 1][num],
                                dpTable[i - 1][num - candyGroup[i].first] +
                                    candyGroup[i].second);
        }
      }
    }

    /* Output */
    cout << dpTable[candyGroup.size() - 1][childMin - 1];
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
