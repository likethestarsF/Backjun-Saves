// 240922 1 #2623
// Class 5
// 00:50
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MY {
  int singerNum, pdNum;
  vector<vector<int>> partialOrder;
  vector<vector<int>> graph;
  vector<int> inDegree;

  /** Topology Sort
   * 1. Push first elems (inDegree == 0)
   * 2. Travel the entire elems
   * 2-1. if q is empty, there is a loop in the graph; multiple push occurred
   * 2-2. update inDegree of children, push child if inDegree == 0
   */
  vector<int> topologySort() {
    bool isPoss = true;
    vector<int> result = {};
    queue<int> q = {};

    // 1
    for (int i = 0; i < singerNum; i++) {
      if (inDegree[i] == 0)
        q.push(i);
    }

    // 2
    for (int i = 0; i < singerNum; i++) {
      // 2-1
      if (q.empty()) {
        isPoss = false;
        break;
      }

      // result
      int cur = q.front();
      result.push_back(cur + 1);
      q.pop();

      // 2-2
      for (int i = 0; i < graph[cur].size(); i++) {
        const int *next = &graph[cur][i];
        inDegree[*next]--;
        if (inDegree[*next] == 0)
          q.push(*next);
      }
    }

    // return result
    if (isPoss)
      return result;
    else
      return {0};
  }

public:
  MY() {
    /* Input */
    cin >> singerNum >> pdNum;

    partialOrder.resize(pdNum, vector<int>());
    for (int i = 0; i < pdNum; i++) {
      int lineN;
      cin >> lineN;

      for (int j = 0; j < lineN; j++) {
        int singer;
        cin >> singer;
        partialOrder[i].push_back(--singer); // index = 0;
      }
    }

    // vector resize
    graph.resize(singerNum, vector<int>()); // vector[parent] = {childs}
    inDegree.resize(singerNum, 0);
  }

  void body() {
    // make Graph with inDegree
    for (int idxMain = 0; idxMain < partialOrder.size(); idxMain++) {
      for (int idxSub = 1; idxSub < partialOrder[idxMain].size(); idxSub++) {
        const int *parent = &partialOrder[idxMain][idxSub - 1];
        const int *child = &partialOrder[idxMain][idxSub];

        graph[*parent].push_back(*child);
        inDegree[*child]++;
      }
    }

    const vector<int> result = topologySort();

    for (const auto elem : result)
      cout << elem << '\n';
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  MY my;
  my.body();
}
