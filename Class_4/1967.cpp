// 240818 1 #1967
// Class 4
// 00:50
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Pair {
  int child, dist;
};

class my {
  int nodeN;
  vector<vector<Pair>> graph; // graph[parent] = {child, dist}}

  int FindMax(int start, bool isMAX) {
    int Max = 0, MaxIdx = 0;
    queue<Pair> q;
    vector<bool> isVisited(nodeN, false);
    q.push({start, 0});
    isVisited[start] = true;

    while (!q.empty()) {
      int cur = q.front().child;
      int curDist = q.front().dist;
      q.pop();

      for (const Pair &elem : graph[cur]) {
        int next = elem.child;
        int nextDist = elem.dist;

        if (isVisited[next] == true)
          continue;

        if (curDist + nextDist > Max) {
          Max = curDist + nextDist;
          MaxIdx = next;
        }

        q.push({next, nextDist + curDist});
        isVisited[next] = true;
      }
    }

    if (isMAX)
      return Max;
    else
      return MaxIdx + 1;
  }

public:
  void body() {
    cin >> nodeN;
    graph.resize(nodeN); // index-0
    for (int repeat = 1; repeat < nodeN; repeat++) {
      int parent, child, dist;
      cin >> parent >> child >> dist;
      parent--, child--;
      graph[parent].push_back({child, dist});
      graph[child].push_back({parent, dist});
    }

    /**
     * Two BFS can fond the diameter of the tree.
     * BFS from Arbitrary node reaches the end of the tree, so called u.
     * (BFS finds the max dist. from start node to somewhere)
     * BFS from u reaches the end of the tree, so called v.
     * the dist, between u and v is the diameter(Maximum dist.).
     */
    int startNode = FindMax(0, false);
    // clog << startNode;

    cout << FindMax(startNode - 1, true);
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