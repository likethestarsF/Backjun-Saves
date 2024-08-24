// 240824 1 #1167
// Class 4
// 00:20
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
  int vertexN;

  int BFS(const vector<vector<Pair>> &graph, const int &start, bool isDist) {
    vector<int> dist(vertexN, -1);
    dist[start] = 0;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (const Pair &edge : graph[cur]) {
        int next = edge.end;
        int nextDist = edge.dist;
        if (dist[next] != -1)
          continue;

        dist[next] = dist[cur] + nextDist;
        q.push(next);
      }
    }

    // Find Max
    int max = 0, maxIdx;
    for (int i = 0; i < vertexN; i++) {
      if (max < dist[i]) {
        max = dist[i];
        maxIdx = i;
      }
    }
    if (isDist)
      return max;
    else
      return maxIdx;
  }

public:
  void body() {
    /* INPUT */
    cin >> vertexN; // [2, 100000]
    vector<vector<Pair>> graph(vertexN);

    for (int i = 0; i < vertexN; i++) {
      int vertex;
      cin >> vertex;

      while (true) {
        int end, dist;
        cin >> end;
        if (end == -1)
          break;
        cin >> dist;

        graph[vertex - 1].push_back({end - 1, dist});
      }
    }

    /**
     * 1. BFS starting from arbitary n(0) to find u (farthest vertex)
     * 2. BFS from u to find v. dist between u and v is the diameter
     * Use 0-based index.
     */
    int u = BFS(graph, 0, false);
    int diameter = BFS(graph, u, true);
    cout << diameter;
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
