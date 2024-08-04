// 240804 4 #15654
// Class 4
// 00:20
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class my {
  int N, M;
  vector<bool> isVisited;
  vector<int> seq = {};

  void backtracking(int depth, vector<int> list) {
    // end of backtracking
    if (depth == M) {
      for (const int &i : list)
        cout << i << ' ';
      cout << '\n';

    } else {
      int start = 0;

      for (int i = start; i < N; i++) {
        if (!isVisited[i]) {
          // select the elem
          list.push_back(seq[i]);
          isVisited[i] = true;

          backtracking(depth + 1, list);

          // deselece the elem
          list.pop_back();
          isVisited[i] = false;
        }
      }
    }
  }

public:
  void body() {
    cin >> N >> M; // [1, 8]

    isVisited.resize(N, false);
    seq.resize(N);
    for (int i = 0; i < N; i++)
      cin >> seq[i]; // [1,10000]
    sort(seq.begin(), seq.end());

    backtracking(0, {});
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