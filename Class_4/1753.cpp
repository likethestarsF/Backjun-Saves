// 240812 3 #1753
// Class 4
// 00:
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 9000000
using namespace std;

struct link {
  int end, weight;
};

class my {
  int vertexN, edgeN;
  // graph[start] = {weight, destaniation}, {,,,} ...
  vector<vector<pair<int, int>>> graph = {};

  vector<int> Dijkstra(int start) {
    vector<int> cost(vertexN + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq = {};

    cost[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
      int curCost = pq.top().first;
      int cur = pq.top().second;
      pq.pop();

      if (curCost > cost[cur])
        continue;

      for (const auto &edge : graph[cur]) {
        int next = edge.second;
        int nextCost = curCost + edge.first;

        if (nextCost < cost[next]) {
          cost[next] = nextCost;
          pq.push({nextCost, next});
        }
      }
    }

    return cost;
  }

public:
  void body() {
    // index 1 style
    cin >> vertexN >> edgeN; //[1, 20000], [1, 300000]
    graph.resize(vertexN + 1);
    int start;
    cin >> start;

    for (int i = 0; i < edgeN; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      graph[u].push_back({w, v});
    }
    vector<int> result = Dijkstra(start);

    for (int i = 1; i <= vertexN; i++) {
      if (result[i] == INF)
        cout << "INF\n";
      else
        cout << result[i] << '\n';
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