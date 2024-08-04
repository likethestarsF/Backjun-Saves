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
  vector<vector<int>> graph;
  vector<int> answers;
  vector<bool> isPushed;

public:
  void body() {
    cin >> nodeN; // [2, 100000]

    // Prevent OoM by decreasing the size of graph.
    // Make the list w/ the help of sort.
    // i = 0 is not used.
    graph.resize(nodeN + 1);
    for (int i = 1; i < nodeN; i++) { // (N-1 times)
      int node1, node2;
      cin >> node1 >> node2; // [1, nodeN]

      // graph[small node][kth] = big node
      if (node1 < node2)
        graph[node1].push_back(node2);
      else
        graph[node2].push_back(node1);
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

      // Find the connection ->
      // Case 1. graph[startIdx][i] = child
      for (int i = 0; i < graph[startIdx].size(); i++) {
        answers[graph[startIdx][i]] = startIdx;
        /// push the next
        if (!isPushed[graph[startIdx][i]]) {
          q.push(graph[startIdx][i]);
          isPushed[graph[startIdx][i]] = true;
        }
      }
      /// rm the connection
      graph[startIdx].resize(0);

      // Case 2. graph[child][i] = startIdx, child is smaller than startIdx
      for (int child = 0; child < startIdx; child++) {
        for (int i = 0; i < graph[child].size(); i++) {
          if (graph[child][i] == startIdx) {
            answers[child] = startIdx;
            /// rm the connection
            graph[child][i] = 0; // erasing can cause problem due to for loop.
            /// push the next
            if (!isPushed[child]) {
              q.push(child);
              isPushed[child] = true;
            }
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