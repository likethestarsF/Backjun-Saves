// 241004 1 #1865
// Class 5
// 00:
#include <algorithm>
#include <iostream>
#include <vector>
#define INF 2147483647
// #define ll long long
using namespace std;

class MY {
  struct edge {
    int start, end, time;
  };
  int vertexNum, roadNum, wormholeNum;
  vector<edge> graph;

public:
  MY() {
    cin >> vertexNum >> roadNum >> wormholeNum; // [,500], [,2500], [,200]
    graph.resize(vertexNum);
  }

  void body() {
    /* Input */
    for (int i = 0; i < roadNum; i++) {
      int start, end, time;
      cin >> start >> end >> time;
      start--, end--;

      graph.push_back({start, end, time});
    }

    for (int i = 0; i < wormholeNum; i++) {
      int start, end, time;
      cin >> start >> end >> time;
      start--, end--;

      graph.push_back({start, end, time * (-1)});
    }

    /** Bellman-Ford
     * Find a route [x] -> ? -> [x], which costs time < 0 : Negative cycle
     * 1. Define starting vertex
     * 2. Initialize a MinDist Table
     * 3. Repeat the below (V-1) times
     * 3-1. Check every edges (connected with the starting point)
     * 3-2. Update the MinDist Table
     * 4. If want to check if there is a negative cycle,
     * * Do 'stage 3' one more: if something changes neg-loop exists.
     * * Since every the length of shortest path without negative cycle,
     * * should be shorter than V-1; visiting every vertices except itself.
     */

    // 1, 2. Suppose, start = 0.
    vector<int> minDist(vertexNum, INF);
    minDist[0] = 0;
    // 3.
    for (int repeat = 0; repeat < vertexNum; repeat++) {
      // 3-1.
      for (const edge &e : graph) {
        if (minDist[e.start] == INF)
          continue;

        // 3-2.
        minDist[e.end] = min(minDist[e.end], minDist[e.start] + e.time);
      }
    }

    // 4.
    bool isNegCycle = false;
    for (const edge &e : graph) {
      if (minDist[e.start] == INF)
        continue;

      if (minDist[e.end] > minDist[e.start] + e.time) {
        isNegCycle = true;
        break;
      }
    }

    /* Output */
    if (isNegCycle)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  int TC;
  cin >> TC;
  while (TC--) {
    MY my;
    my.body();
  }
}
