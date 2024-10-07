// 241007 2 #16928
// Class 3
// 00:30
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
// #define INF 1e8
// #define MAX 2147483647
// #define ll long long
using namespace std;

class MY {
  struct dice {
    int loca, cnt;
  };
  int ladderNum, snakeNum;

  template <typename T> int BFS(const T &graph) {
    vector<bool> isVisited(100, false);
    int result = 0;

    queue<dice> q;
    q.push({0, 0});
    isVisited[0] = true;

    while (!q.empty()) {
      const dice cur = q.front();
      q.pop();

      for (int i = 1; i <= 6; i++) {
        const int next = cur.loca + i;
        const int nextCnt = cur.cnt + 1;

        // END of BFS
        if (next == 100 - 1)
          return nextCnt;

        if (isVisited[next])
          continue;

        // 1-1. Check if there's graph : No
        if (graph[next] == -1) {
          q.push({next, nextCnt});
          isVisited[next] = true;
        }

        // 1-2. Connection exists (99 isn't included)
        else {
          const int nextNext = graph[next];

          if (isVisited[nextNext])
            continue;

          q.push({nextNext, nextCnt});
          isVisited[next] = isVisited[nextNext] = true;
        }
      }
    }

    return result;
  }

public:
  // MY() {}

  void body() {
    /* input */
    cin >> ladderNum >> snakeNum;
    vector<int> graph(100, -1);
    for (int i = 0; i < ladderNum; i++) {
      int start, end;
      cin >> start >> end;
      graph[--start] = --end;
    }

    for (int i = 0; i < snakeNum; i++) {
      int start, end;
      cin >> start >> end;
      graph[--start] = --end;
    }

    /** Graph, BFS
     * 1. Travel (cur + [1,6]); Boundary Check, visited Check
     * * update isVisited only when pushed
     */
    cout << BFS(graph);
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
