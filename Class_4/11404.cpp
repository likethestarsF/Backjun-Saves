// 240821 2 #11404
// Class 4
// 00:40
#include <algorithm>
#include <iostream>
#include <vector>
#define INF 2000000000
#define ll long long
using namespace std;
class my {
  int cityN, busN;
  vector<vector<ll int>> graph;

  /**
   * Find the shortest path starting from every vertex,
   * comparing dist(a to b) with dist(a -> mid -> b)
   * Time Complexity will be O(N^3) : triple for loop
   */
  void Floyd_Warshall(vector<vector<ll int>> &graph) {
    // initialization
    vector<vector<ll int>> dist = graph;

    for (int mid = 0; mid < cityN; mid++)
      for (int start = 0; start < cityN; start++)
        for (int end = 0; end < cityN; end++) {
          // disconnected case
          if (dist[start][mid] == INF || dist[mid][end] == INF)
            continue;
          if (dist[start][mid] + dist[mid][end] < dist[start][end])
            dist[start][end] = dist[start][mid] + dist[mid][end];
        }

    // printing
    for (int i = 0; i < cityN; i++) {
      for (int j = 0; j < cityN; j++) {
        if (dist[i][j] == INF)
          cout << "0 ";
        else
          cout << dist[i][j] << ' ';
      }
      cout << '\n';
    }
  }

public:
  void body() {
    /* INPUT */
    cin >> cityN >> busN; // [2, 100], [1,100000]
    graph.resize(cityN, vector<ll int>(cityN, INF));
    for (int i = 0; i < busN; i++) {
      int start, end, cost;
      cin >> start >> end >> cost;
      start--, end--;
      graph[start][end] = min((ll int)cost, graph[start][end]);
    }
    for (int i = 0; i < cityN; i++)
      graph[i][i] = 0;

    /* MAIN */
    Floyd_Warshall(graph);
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