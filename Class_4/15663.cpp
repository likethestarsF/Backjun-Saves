// 240805 1 #15663
// Class 4
// 00:
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
  vector<bool> isVisited;
  void backtracking(int depth) {
    // Exit
    if (depth == M) {
      for (const int &elem : answer)
        cout << elem << ' ';
      cout << '\n';

      previous = answer;
    }

    else {
      for (int i = 0; i < N; i++) {
        /*
         * Do not Select an indentical number value in the same depth
         * Refresh the marker for the above when a depth is decreased
         * and depth is decreased only when it reaches the end.
         * this is implemented by previous[depth] != num[i] :

         */
        if (!isVisited[i] && previous[depth] != num[i]) {
          // Select
          answer[depth] = num[i];
          isVisited[i] = true;

          backtracking(depth + 1);

          // Deselect
          isVisited[i] = false;
        }
      }
    }
  }

public:
  void body() {
    // #input
    cin >> N >> M; // [1, 8], M <= N
    num.resize(N);
    for (int i = 0; i < N; i++)
      cin >> num[i]; // [1, 10000]
    sort(num.begin(), num.end());

    // sorted by inc. dictionary order
    answer.resize(M, 0);
    previous.resize(M);
    isVisited.resize(M, false);
    backtracking(0);
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