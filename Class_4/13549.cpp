// 240811 6 #13549
// Class 4
// 00:
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class my {
  int start, target;

  int BFS() {
    int time = 0;
    bool isEnd = false;

    vector<bool> isVisited(100001, false);
    queue<int> q = {};
    queue<int> q_next = {};
    const queue<int> q_empty = {};
    q.push(start);

    while (!q.empty()) {

      while (!q.empty()) {
        int cur = q.front();
        isVisited[cur] = true;
        q.pop();

        // Is it finished?
        if (cur * 2 == target)
          return time;
        else if (cur + 1 == target || cur - 1 == target)
          isEnd = true; // return time + 1

        // Push nexts COND: boundary
        //  0. *2, time : + 0
        if (cur * 2 < 100001 && !isVisited[cur * 2] && cur <= target) {
          q.push(cur * 2);
          isVisited[cur * 2];
        }

        //  1. +1, time : + 1
        if (cur + 1 < 100001 && !isVisited[cur + 1]) {
          q_next.push(cur + 1);
          isVisited[cur + 1];
        }

        //  2. -1, time : + 1
        if (cur - 1 >= 0 && !isVisited[cur - 1]) {
          q_next.push(cur - 1);
          isVisited[cur - 1];
        }
      }

      if (isEnd)
        return time + 1;

      // Update q by q_next
      q = q_next;
      q_next = q_empty;
      time++;
    }

    return -1; // error
  }

public:
  void body() {
    cin >> start >> target; // [1, 100000]

    cout << BFS();
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