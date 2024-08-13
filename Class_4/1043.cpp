// 240813 1 #1043
// Class 4
// 01:00
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class my {
  int manN, partyN;
  int knowingTruthN;
  vector<int> knowingTruth = {};
  vector<bool> isVisited = {};
  vector<vector<bool>> graph = {};
  vector<vector<int>> partyList = {};

  void TravelGraph(const int &start) {
    if (isVisited[start])
      return;

    queue<int> q = {};
    q.push(start);
    isVisited[start] = true;

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (int next = 1; next <= manN; next++) {
        if (graph[cur][next] && !isVisited[next]) {
          q.push(next);
          isVisited[next] = true;
        }
      }
    }
  }

public:
  void body() {
    cin >> manN >> partyN; // [1, 50]
    cin >> knowingTruthN;  // [1, manN]

    graph.resize(manN + 1, vector<bool>(manN + 1, false)); // [, 51 X 51]
    isVisited.resize(manN + 1, false);
    isVisited[0] = true;

    for (int i = 0; i < knowingTruthN; i++) {
      int n;
      cin >> n;
      knowingTruth.push_back(n);
    }

    // Input members for updating connections
    while (partyN--) {
      int participantN;
      cin >> participantN;
      vector<int> list = {};
      while (participantN--) {
        int n;
        cin >> n;
        list.push_back(n);
      }

      partyList.push_back(list);

      // Update the graph connections
      if (list.size() <= 1)
        continue;
      for (int i = 1; i < list.size(); i++) {
        graph[list[i - 1]][list[i]] = true;
        graph[list[i]][list[i - 1]] = true;
      }
    }

    /**
     * Do not push if there' s a person who knows the truth
     * Make the people who company with truth-knower.
     * Recheck the remain parties. if a truth-knower is added. : O(N^x)
     */

    /**
     * Or make the graph, connect every party members together.
     *   Take edges with everyone in the parties(avoiding Too many connects)
     *   Sequential can be enough, as we travel everywhere we can go.
     *   (omni-directional)
     *
     * Go around the graph starting from truth-knower. (Traversal) : by BFS
     * If there's a party with only unvisited person after Traversal,
     *   Add + 1 to the answer for each parties. : O(N)
     */

    for (const auto &man : knowingTruth)
      TravelGraph(man);

    int answer = 0;
    for (int i = 0; i < partyList.size(); i++) {
      bool canLie = true;

      for (int j = 0; j < partyList[i].size(); j++) {
        if (isVisited[partyList[i][j]]) {
          canLie = false;
          break;
        }
      }

      if (canLie)
        answer++;
    }

    cout << answer << '\n';
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