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
  vector<vector<int>> graphRev;

  void travelGraph(/* const int &start, vector<bool> &isVisited */) {
    vector<bool> isVisited(studentNum, false);
    // Find the vertices which has no parent && Unvisited
    while (true) {
      queue<int> q = {};

      for (int i = 0; i < studentNum; i++) {
        if (!isVisited[i] && graph[i].empty())
          q.push(i);
      }

      if (q.empty())
        break; // Exit

      while (!q.empty()) {
        int cur = q.front();
        isVisited[cur] = true;
        cout << cur + 1 << ' ';
        q.pop();

        // Remove the edges which 'cur' is the parent
        for (int i = 0; i < graphRev[cur].size(); i++) {
          // find 'cur' in the graph and erase.
          int valueShort = graphRev[cur][i];
          auto itr =
              find(graph[valueShort].begin(), graph[valueShort].end(), cur);
          if (itr != graph[valueShort].end())
            graph[valueShort].erase(itr);
        }
      }
    }
  }

public:
  void body() {
    /* Input */
    cin >> studentNum >> compareNum;          // [1, 32000], [1, 1e5]
    graph.resize(studentNum, vector<int>(0)); // graph[x] = {a, ...} a is taller
    graphRev.resize(studentNum, vector<int>(0));
    for (int i = 0; i < compareNum; i++) {
      int taller, shorter;
      cin >> taller >> shorter;
      taller--, shorter--;
      graph[shorter].push_back(taller);
      graphRev[taller].push_back(shorter);
    }

    /** sorta Topology Sort
     * 1. travel the entire verteices
     * 2. find vertices which has no parent(degree==0), add them in to a queue.
     * 3. while(!queue.empty). delete the edges of each vertex and print them.
     *  Use graphRev to save which vertex is connected.
     *  This is used not to travel entire graph when we delete edge.
     * 4. if queue is empty, goto 2. again.
     * 5. if there's no vertex left, Finish.
     */
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
