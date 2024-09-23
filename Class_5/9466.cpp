// 240923 2 #9466
// Class 5
// 00:50
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define INF 2e9
using namespace std;

class MY {
  int studentNum;
  vector<int> graph;

  int teamMemberNumber() {
    int teamMemberNum = 0;
    vector<bool> isInTeam(studentNum, false);

    for (int i = 0; i < studentNum; i++) {
      if (isInTeam[i])
        continue;
      vector<bool> isVisited = isInTeam;

      queue<int> q;
      q.push(i);
      while (!q.empty()) {
        int cur = q.front();
        isVisited[cur] = true;
        q.pop();
        int next = graph[cur];

        // go to next
        if (!isVisited[next])
          q.push(next);

        // update isInTeam
        else {
          // there's a loop in the current queue.
          // It is needed to distingush loop members from non-loop members.
          if (!isInTeam[next]) {
            teamMemberNum += countMembers(next);
          }

          // Everyone visited by current queue now belongs to a team.
          // they must be a team member, or a non-team member.
          // Anyway, No matter where theys belongs, they belongs to something.
          isInTeam = isVisited;

          // End of While() Loop
          break;
        }
      }
    }

    return teamMemberNum;
  }

  int countMembers(const int &root) {
    int cnt = 0;
    int cur = root;
    int next = root;
    while (true) {
      cur = next;
      cnt++;
      next = graph[cur];

      if (next == root)
        break;
    }

    return cnt++;
  }

public:
  MY() {
    /* Input */
    cin >> studentNum; // [,1e5]
    graph.resize(studentNum);
    for (int curr = 0; curr < studentNum; curr++) {
      int next;
      cin >> next;
      graph[curr] = --next;
    }
  }

  void body() {
    /**
     * 1. Team exists when a loop exists
     * 2. Therefore, it is needed to find a loop.
     * 3. Travel each nodes,
     * 4. if it is already in the loop, pass it; use isInTeam
     */
    int result = studentNum - teamMemberNumber();
    cout << result << '\n';
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  int testNum;
  cin >> testNum;
  while (testNum--) {
    MY my;
    my.body();
  }
}
