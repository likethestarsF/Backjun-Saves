// 240923 2 #9466
// Class 5
// 01:00
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
      int next = i;

      while (true) {
        int cur = next;
        isVisited[cur] = true;
        next = graph[cur];

        // 1. Go to next
        if (!isVisited[next])
          continue;

        // 2. Update isInTeam

        // 2-1. If a loop is in the current queue.
        // * it is needed to distingush loop members from non-loop members.
        if (!isInTeam[next])
          teamMemberNum += countMembers(next);

        // 2-2. Everyone visited by current queue now belongs to a team.
        // * they must be a team member, or a non-team member.
        // * anyway, No matter where they belong, they belong to somewhere.
        isInTeam = isVisited;

        break; // End of While() Loop
      }
    }

    return teamMemberNum;
  }

  int countMembers(const int &root) {
    int cnt = 0;
    int next = root;
    while (true) {
      int cur = next;
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
