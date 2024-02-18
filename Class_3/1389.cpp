// 240218 7 #1389
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class my {
  int userNum;
  vector<vector<int>> adjList;

public:
  void in(int n, int relationshipNum) {
    userNum = n;
    adjList.resize(userNum);
    for (int i = 0; i < relationshipNum; i++) {
      int u1, u2;
      cin >> u1 >> u2;
      // user  : 1, 2, 3, ..., n
      // index : 0, 1, 2, ..., n-1 : so -1
      adjList[u1 - 1].push_back(u2 - 1);
      adjList[u2 - 1].push_back(u1 - 1);
    }
  }

  int KevinNumForOne(const int &start) {
    vector<int> distance(userNum, -1);

    // need to use DFS : queue
    // save the relationship in the dpTable.
    queue<int> toCheck = {};
    toCheck.push(start);
    distance[start] = 0;

    while (!toCheck.empty()) {
      int current = toCheck.front();
      toCheck.pop();

      // add adj vertexs to the queue
      for (const auto &vertex : adjList[current]) {
        if (vertex == current)
          continue;

        if (distance[vertex] == -1) {
          toCheck.push(vertex);
          distance[vertex] = distance[current] + 1;
        }
      }
    }
    int sum = 0;
    for (const auto &elem : distance) {
      sum += elem;
    }

    return sum;
  }

  int findMin() {
    int index = 0;
    int min = KevinNumForOne(index);
    for (int i = 1; i < userNum; i++) {
      int current = KevinNumForOne(i);
      if (min == current)
        index = (index > i) ? i : index;
      else if (min > current) {
        min = current;
        index = i;
      }
    }

    return (index + 1);
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
  int n, m;
  cin >> n >> m;
  a.in(n, m);
  // cout << a.KevinNumForOne(1);
  cout << a.findMin();
}