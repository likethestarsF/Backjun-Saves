// 240823 1 #1238
// Class 4
// 00:40
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 1000000000
using namespace std;

class my {
  struct Pair {
    int end, dist;
  };
  struct comp {
    bool operator()(Pair &a, Pair &b) { return a.dist > b.dist; }
  };
  int vertexN, edgeN, target;
  vector<vector<Pair>> graph;
  vector<vector<Pair>> graph_rev;

  vector<int> Dijkstra(const vector<vector<Pair>> &graph, const int &start) {
    vector<int> dist(vertexN, INF);
    dist[start] = 0;
    priority_queue<Pair, vector<Pair>, comp> pq;
    pq.push({start, 0});

    while (!pq.empty()) {
      int cur = pq.top().end;
      int curDist = pq.top().dist;
      pq.pop();

      if (curDist > dist[cur])
        continue;

      for (const Pair &edge : graph[cur]) {
        int next = edge.end;
        int nextDist = edge.dist;
        if (dist[next] > dist[cur] + nextDist) {
          dist[next] = dist[cur] + nextDist;
          pq.push({next, dist[next]});
        }
      }
    }

    return dist;
  }

public:
  void body() {
    /* INPUT */
    cin >> vertexN >> edgeN; // [1, 1000], [1, 10000]
    cin >> target;           // [1, N];
    target--;                // transfer to 0 based index

    graph.resize(vertexN);
    graph_rev.resize(vertexN);
    while (edgeN--) {
      int start, end, dist;
      cin >> start >> end >> dist;
      graph[start - 1].push_back({end - 1, dist});
      graph_rev[end - 1].push_back({start - 1, dist});
    }

    vector<int> AllToOne = Dijkstra(graph, target);
    vector<int> OneToAll = Dijkstra(graph_rev, target);

    int max = 0;
    for (int i = 0; i < vertexN; i++)
      if (AllToOne[i] + OneToAll[i] > max)
        max = AllToOne[i] + OneToAll[i];

    cout << max;
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