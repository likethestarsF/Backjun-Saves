// 240306 2 #11403
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Route_finder {
  vector<vector<bool>> graph;
  int N; // number of Vertex

public:
  Route_finder(int &n) {
    graph.resize(n, vector<bool>(n));
    N = n;
  }

  void input(int &row) {
    for (int i = 0; i < N; i++) {
      bool temp;
      cin >> temp;
      graph[row][i] = temp;
    }
  }

  /* BFS for a vertex
  ** when do push, update visited simultaneously
  ** to avoid duplicated i insertion
  */
  void calc(int &vertex) {
    queue<int> BFS;
    vector<bool> visited(N, false);

    // init the BFS
    for (int i = 0; i < N; i++)
      if (graph[vertex][i]) {
        BFS.push(i);
        visited[i] = true;
      }

    while (!BFS.empty()) {
      int cur = BFS.front();
      BFS.pop();
      for (int i = 0; i < N; i++)
        if (graph[cur][i] && !visited[i]) {
          BFS.push(i);
          visited[i] = true;
        }
    }

    // print out the answer
    for (int i = 0; i < N; i++) {
      cout << visited[i] << " ";
    }
    cout << '\n';
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  int n;
  cin >> n;
  Route_finder a(n);
  for (int i = 0; i < n; i++) {
    a.input(i);
  }

  for (int v = 0; v < n; v++) {
    a.calc(v);
  }
}