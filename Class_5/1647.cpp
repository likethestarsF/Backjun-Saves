// 240910 1 #1647
// Class 5
// 00:20
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long
#define INF 2147483647
using namespace std;

class my {
  struct edge {
    int next, dist;
  };
  struct compare {
    bool operator()(edge &a, edge &b) { return a.dist > b.dist; }
  };

  int vertexN, edgeN;
  vector<vector<edge>> graph;

  /**
   * how to divided the graph into two parts?
   * Find the long-tailed shortest path in the graph.
   * Delete the edge which has a maximum distance in that long-tail.
   */
  vector<int> findSpanningTree(const int &start) {
    vector<int> dist(vertexN, INF);
    vector<bool> isVisited(vertexN, false);
    priority_queue<edge, vector<edge>, compare> pq = {};
    pq.push({start, 0});

    while (!pq.empty()) {
      int cur = pq.top().next;
      int curDist = pq.top().dist;
      pq.pop();

      if (isVisited[cur])
        continue;

      dist[cur] = curDist;

      for (const auto &edge : graph[cur]) {
        int next = edge.next;
        int nextDist = edge.dist;

        if (isVisited[next])
          continue;

        pq.push({next, nextDist});
      }

      isVisited[cur] = true;
    }

    return dist;
  }

public:
  void body() {
    /* INPUT */
    cin >> vertexN >> edgeN; // [2, 100000], [1, 1000000]
    graph.resize(vertexN);
    for (int i = 0; i < edgeN; i++) {
      int start, end, dist;
      cin >> start >> end >> dist; // dist~[1, 1000]
      start--, end--;
      graph[start].push_back({end, dist});
      graph[end].push_back({start, dist});
    }

    // find Spanning Tree
    vector<int> spanningTree = findSpanningTree(0);

    // find maxDist of Tree : to delete it
    int maxDist = 0;
    ll int sum = 0;
    for (const int &dist : spanningTree) {
      sum += dist;
      maxDist = std::max(maxDist, dist);
    }

    cout << sum - maxDist;
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
