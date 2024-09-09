// 240909 1 #1197
// Class 5
// 00:45
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long
#define INF 2147483647
using namespace std;

class my {
  struct edge {
    int next;
    ll int dist;
  };
  struct compare {
    bool operator()(edge &a, edge &b) { return a.dist > b.dist; }
  };

  int vertexN, edgeN;
  vector<vector<edge>> graph;

  /**
   * Prim's Algorithm
   */
  int findSpanningTree(const int &start) {
    vector<ll int> dist(vertexN, INF);
    priority_queue<edge, vector<edge>, compare> pq = {};
    pq.push({start, 0});
    dist[start] = 0;

    while (!pq.empty()) {
      int cur = pq.top().next;
      pq.pop();

      // pass if already visited

      for (const edge &edge : graph[cur]) {
        int next = edge.next;
        int nextDist = edge.dist;

        if (dist[next] > nextDist) {
          dist[next] = nextDist;
          pq.push({next, dist[next]});
        }
      }
    }

    ll int distSum = 0;
    for (auto &elem : dist)
      distSum += elem;

    return distSum;
  }

public:
  void body() {
    /* INPUT */
    cin >> vertexN >> edgeN;
    graph.resize(vertexN);
    for (int i = 0; i < edgeN; i++) {
      int start, end;
      ll int dist;
      cin >> start >> end >> dist;
      start--, end--; // 0-style index
      graph[start].push_back({end, dist});
    }

    // Print entire dists of spanning Tree
    cout << findSpanningTree(0);
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
