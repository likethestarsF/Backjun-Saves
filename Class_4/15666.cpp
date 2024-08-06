// 240806 2 #15666
// Class 4
// 00:30
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {
  int N, M;
  vector<int> num;
  vector<int> answer;

  vector<int> previous;
  void UpdatePrevious(int depth) {
    previous[depth] = answer[depth];
    for (int i = depth + 1; i < M; i++)
      previous[i] = 0;
  }

  /*
   * By previous vector, avoid the duplicated results.
   * By sorting and i = start, select numbers inc. order.
   */
  void backtracking(int depth, int start) {
    // Exit
    if (depth == M) {
      for (const auto &elem : answer)
        cout << elem << ' ';
      cout << '\n';
    }

    else {
      for (int i = start; i < N; i++) {
        // COND.
        if (num[i] != previous[depth]) {
          // Select
          answer[depth] = num[i];
          UpdatePrevious(depth);

          backtracking(depth + 1, i);

          // Deselect
        }
      }
    }
  }

public:
  void body() {
    cin >> N >> M; // [1, 8]
    num.resize(N);
    for (int i = 0; i < N; i++)
      cin >> num[i];              // [1, 10000]
    sort(num.begin(), num.end()); // inc. order

    answer.resize(M, 0);
    previous.resize(M, 0);
    backtracking(0, 0);
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