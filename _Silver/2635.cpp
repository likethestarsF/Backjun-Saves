// 240814 1 #2635
// Random Marathon 11 E
// 00:00
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class my {
  int first;

  int FindRepeated(int second) {
    int cnt = 0 + 2;        // first, second
    int cur = second;       // second
    int next = first - cur; // third
    if (next < 0)
      return cnt;

    while (next >= 0) {
      cnt++;
      int prev = cur;
      cur = next;
      next = prev - cur;
    }

    return cnt;
  }

  void PrintAnswer(int i) {
    int cur = first;
    int next = i;

    cout << cur << ' ';

    while (next >= 0) {
      cout << next << ' ';
      int prev = cur;
      cur = next;
      next = prev - cur;
    }
  }

public:
  void body() {
    cin >> first; //[1, 30000]

    int max = 0;
    int idxMax = 0;
    for (int i = 1; i <= first; i++) {
      int cur = FindRepeated(i);
      if (max < cur) {
        max = cur;
        idxMax = i;
      }
    }

    cout << max << '\n';
    PrintAnswer(idxMax);
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