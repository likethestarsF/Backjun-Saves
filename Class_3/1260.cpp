// 240218 6 #1260
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class my {
  int startPoint;
  int numVertex;

public:
  vector<vector<bool>> table;
  void input(const int &numOfVertex, const int &numOfEdge,
             const int &startingVertex) {
    // init the table for graph
    table.resize(numOfVertex, vector<bool>(numOfVertex, false));

    for (int i = 0; i < numOfEdge; i++) {
      int v1, v2;
      // index: 0,1,2 ...
      // vertex: 1,2,3 ... so -1
      cin >> v1 >> v2;
      table[v1 - 1][v2 - 1] = true;
      table[v2 - 1][v1 - 1] = true;
    }

    numVertex = numOfVertex;
    startPoint = startingVertex - 1;
  }

  // use stack
  void DFS(vector<vector<bool>> table) {
    stack<int> toVisit = {};
    vector<bool> visited(numVertex, false);
    toVisit.push(startPoint);

    while (!toVisit.empty()) {
      int current = toVisit.top();

      if (!visited[current])
        cout << current + 1 << ' ';
      visited[current] = true;

      bool flag = true;
      for (int i = 0; i < numVertex; i++) {
        if (!visited[i] && table[current][i] && i != startPoint) {
          toVisit.push(i);
          table[i][current] = false;
          table[current][i] = false;
          flag = false;
          break;
        }
      }
      if (flag)
        toVisit.pop();
    }

    cout << '\n';
  }

  // use queue
  void BFS() {
    queue<int> toVisit = {};
    vector<bool> visited(numVertex, false);
    toVisit.push(startPoint);
    visited[startPoint] = true;

    while (!toVisit.empty()) {
      int current = toVisit.front();
      toVisit.pop();

      cout << current + 1 << ' ';

      for (int i = 0; i < numVertex; i++) {
        if (table[current][i] && !visited[i]) {
          toVisit.push(i);
          visited[i] = true;
        }
      }
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
  int n, m, v;
  cin >> n >> m >> v;
  a.input(n, m, v);
  a.DFS(a.table);
  a.BFS();
}