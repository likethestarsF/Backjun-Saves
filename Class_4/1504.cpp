// 240814 2 #1504
// Class 4
// 01:20
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 1000000000
using namespace std;

struct edge {
  int to, dist;
};
struct comp {
  bool operator()(edge &a, edge &b) { return a.dist > b.dist; }
};

class my {
  int vertexN, edgeN;
  int target[2];

  vector<vector<edge>> graph = {};
  vector<int> dist;
  void Dijkstra(const int &start) {
    dist.assign(vertexN, INF);
    priority_queue<edge, vector<edge>, comp> pq = {};
    pq.push({start, 0});
    dist[start] = 0;

    while (!pq.empty()) {
      int cur = pq.top().to;
      int curDist = pq.top().dist;
      pq.pop();

      if (curDist > dist[cur])
        continue;

      for (const auto &edge : graph[cur]) {
        int next = edge.to;
        int nextDist = curDist + edge.dist;

        if (nextDist < dist[next]) {
          dist[next] = nextDist;
          pq.push({next, nextDist});
        }
      }
    }
  }

public:
  void body() {

    // Input
    cin >> vertexN >> edgeN; // [2, 800] , [0, 200000]
    graph.resize(vertexN);
    while (edgeN--) {
      int a, b, dist;
      // a and b should be -1, for index 0 system
      cin >> a >> b >> dist; // dist[1, 1000]
      a--, b--;
      graph[a].push_back({b, dist});
      graph[b].push_back({a, dist});
    }

    cin >> target[0] >> target[1];
    target[0]--, target[1]--;

    /**
     * Dijkstra with Priority Queue.
     * The route has to pass targets.
     *   0 -> target0 -> target1 -> vertexN-1
     *   Or 0 -> target0 -> target1 -> vertexN-1
     * Select one of them by min (dist[target[0], + dist[target[1]])
     */

    Dijkstra(0);

    // Not three vertices are fully connected
    if (dist[target[0]] == INF || dist[target[1]] == INF ||
        dist[vertexN - 1] == INF) {
      cout << -1;
      return;
    }

    // 1st case. 1 -> tar1 -> tar2 -> vertexN-1
    // 2nd case. 1 -> tar2 -> tar1 -> vertexN-1
    int case1 = dist[target[0]], case2 = dist[target[1]];
    Dijkstra(target[0]); // dist between tar1 and tar2 are the same.
    case1 += dist[target[1]];
    case2 += dist[target[1]];

    case2 += dist[vertexN - 1];
    Dijkstra(target[1]);
    case1 += dist[vertexN - 1];

    cout << min(case1, case2);
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
