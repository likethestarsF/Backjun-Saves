// 240811 2 #1916
// Class 4
// 00:
#include <algorithm>
#include <iostream>
#include <vector>
#define INF 2000000000
using namespace std;

class my {
  int cityN, busN;
  vector<vector<int>> graph; // [start][end] = cost; 1000*1000

  int FindMin(int start, int end) {
    vector<int> cost(cityN, INF);
    vector<bool> isVisited(cityN, false);
    int cur = start;
    cost[cur] = 0;

    // Exit when every nodes are visited
    while (true) {
      isVisited[cur] = true;

      // update costs nearby of cur
      for (int i = 0; i < graph[cur].size(); i++) {
        if (graph[cur][i] == INF)
          continue; // disconntected is ignored
        cost[i] = min(cost[i], cost[cur] + graph[cur][i]);
      }

      // update cur
      int minCost = INF;
      int next = -1;
      for (int i = 0; i < graph[cur].size(); i++) {
        if (graph[cur][i] == INF || isVisited[i])
          continue; // disconntected and visited are ignored

        if (graph[cur][i] <= minCost) {
          next = i;
          minCost = graph[cur][i];
        }
      }

      if (next == -1)
        break; // Exit of While
      else
        cur = next;
    }

    return cost[end];
  }

public:
  void body() {
    cin >> cityN >> busN; // [1,1000], [1,100000]
    graph.resize(cityN, vector<int>(cityN, INF));
    for (int i = 0; i < busN; i++) {
      int start, end, cost;
      cin >> start >> end >> cost; // cost=[0, 100000]
      graph[start - 1][end - 1] =
          min(graph[start - 1][end - 1], cost); // to use [0]
    }

    int a, b;
    cin >> a >> b;
    cout << FindMin(a - 1, b - 1);
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