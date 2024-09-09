// 240909 1 #1197
// Class 5
// 01:20
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
   * Prim's Algorithm :
   * finding a vertex that has a minimum dist for now.
   * the vertext is next to the the every vertex currently selected.
   * It should select edges to connect every vertex each other.

   * dist to a vertex is updated after visiting that vertex itself.
   * minDist is selected everytimes since it's sorting dists by priority_queu.
   */
  int findSpanningTree(const int &start) {
    vector<ll int> dist(vertexN, INF);
    vector<bool> isVisited(vertexN, false);
    priority_queue<edge, vector<edge>, compare> pq = {};
    pq.push({start, 0});

    while (!pq.empty()) {
      int cur = pq.top().next;
      int curDist = pq.top().dist;
      pq.pop();

      // pass if cur is already visited
      if (isVisited[cur])
        continue;

      /** update dist
       * guess that since queue is already sorted,
       * and we also isVisted marker, this Cond. always be true
       */
      if (dist[cur] > curDist)
        dist[cur] = curDist;

      for (const edge &edge : graph[cur]) {
        int next = edge.next;
        int nextDist = edge.dist;

        // pass if next is already visited, no to do useless pushing
        if (isVisited[next])
          continue;

        // push if the next is an unvisited vertex
        pq.push({next, nextDist});
      }

      // update isVisited marker after visiting adjacents
      isVisited[cur] = true;
    }

    // calc. the sum of dist
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
