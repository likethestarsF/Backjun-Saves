// 240919 1 #2252
// Class 5
// 00:50
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
  vector<vector<short>> graphTable;

  /** sorta Topology Sort
   * 1. travel the entire node
   * 2. find vertices which has no parent(degree==0), add them in to a queue.
   * 3. while(!queue.empty). delete the edges of each vertex and print them.
   * 4. if queue is empty, goto 2. again.
   * 5. if there's no vertex left, Finish.
   */
  void travelGraph(const int &start, vector<bool> &isVisited) {

    // Find the vertices which has no parent

    queue<int> q = {};

    ;
    /* Output */
    ;
  }

public:
  void body() {
    /* Input */
    cin >> studentNum >> compareNum; // [1, 32000], [1, 1e5]
    // graph[x][y] = 1, x is taller, [x][y] =-1, y is taller
    graphTable.resize(studentNum, vector<short>(studentNum, 0));
    for (int i = 0; i < compareNum; i++) {
      int taller, shorter;
      cin >> taller >> shorter;
      taller--, shorter--;
      graphTable[taller][shorter] = 1;
      graphTable[shorter][taller] = -1;
    }

    /**
     * If the graph is disconnected, Don't need to care the order.
     * We only have to treat the order in the same graph.
     * Since we don't know graph is not unified,
     * -> isVisited is essential, to travel all vetices.

     * 1. start traveling from the first, arbitrary student.
     * 2. If the travel is terminated, find the unvisited by isVisited marker.
     * 3. Repeat this.
     */
    vector<bool> isVisited(studentNum, false);
    for (int i = 0; i < studentNum; i++) {
      if (!isVisited[i])
        travelGraph(i, isVisited);
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
  a.body();
}
