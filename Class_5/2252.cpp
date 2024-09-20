// 240919 3 #2252
// Class 5
// 01:30
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long
using namespace std;

class my {
  template <typename T> void testArr(T k, bool exitFlag) {
    for (auto e : k)
      clog << e << endl;
    if (exitFlag)
      exit(1);
  }

  int studentNum, compareNum;
  vector<vector<int>> graph;
  vector<int> inDegree;

  // Topology Sort
  void travelGraph() {
    queue<int> q = {};

    // first push to initalize
    for (int i = 0; i < studentNum; i++) {
      if (inDegree[i] == 0)
        q.push(i);
    }

    for (int i = 0; i < studentNum; i++) {
      if (q.empty())
        return; // EXIT; There is a loop in the graph

      int cur = q.front();
      cout << cur + 1 << ' ';
      q.pop();

      // push after finishing the current node
      for (int i = 0; i < graph[cur].size(); i++) {
        int next = graph[cur][i];
        inDegree[next]--;
        if (inDegree[next] == 0)
          q.push(next);
      }
    }
  }

public:
  void body() {
    /* Input */
    cin >> studentNum >> compareNum;          // [1, 32000], [1, 1e5]
    graph.resize(studentNum, vector<int>(0)); // graph[x] = {a, ...} x is taller
    inDegree.resize(studentNum, 0);
    for (int i = 0; i < compareNum; i++) {
      int taller, shorter;
      cin >> taller >> shorter;
      taller--, shorter--;
      graph[taller].push_back(shorter);
      inDegree[shorter]++;
    }

    travelGraph();
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
