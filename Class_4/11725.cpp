// 240804 6 #11725
// Class 4
// 00:
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class my {
  int nodeN;
  vector<vector<bool>> graph;
  vector<int> answers;
  vector<bool> isPushed;

  void RmConnections(int startIdx, int i) {
    graph[startIdx][i] = false;
    graph[i][startIdx] = false;
  }

public:
  void body() {
    cin >> nodeN; // [2, 100000]

    // i = 0 is not used.
    graph.resize(nodeN + 1, vector<bool>(nodeN + 1, false));
    for (int i = 1; i < nodeN; i++) { // (N-1 times)
      int node1, node2;
      cin >> node1 >> node2; // [1, nodeN]
      graph[node1][node2] = true;
      graph[node2][node1] = true;
    }

    // ## Process
    answers.resize(nodeN + 1, 0);
    isPushed.resize(nodeN + 1, false);
    // init. the queue for BFS
    queue<int> q = {};
    int startIdx = 1;

    q.push(startIdx);
    isPushed[startIdx] = true;
    while (!q.empty()) {
      // load the front
      startIdx = q.front();
      q.pop();

      for (int i = 1; i <= nodeN; i++) {
        if (graph[startIdx][i]) {
          answers[i] = startIdx;
          RmConnections(startIdx, i);

          if (!isPushed[i]) {
            q.push(i);
            isPushed[i] = true;
          }
        }
      }
    }

    // output
    for (int i = 2; i <= nodeN; i++) {
      cout << answers[i] << '\n';
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