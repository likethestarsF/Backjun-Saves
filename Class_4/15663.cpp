// 240805 0 #15663
// 240806 1 #15663
// Class 4
// 02:20
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {
  int N, M;
  vector<int> num;

  void UpdatePrevious(int depth) {
    previous[depth] = answer[depth];
    for (int i = depth + 1; i < M; i++)
      previous[i] = 0;
  }

  vector<int> answer;
  vector<int> previous;
  vector<bool> isVisited;
  void backtracking(int depth) {
    // Exit
    if (depth == M) {
      for (const int &elem : answer)
        cout << elem << ' ';
      cout << '\n';
    }

    else {
      for (int i = 0; i < N; i++) {
        /*
         * Do not Select an identical to previous number in the same depth
         * refresh the previous whenever a new num. is selected:
         * targets are [depth] itself and every previous[i]; i is bigger than
         * the depth. this is implemented by UpdatePrevious[depth]
         * By only comparing num[i] with previous[depth], we can avoid the
         * duplicated selction.
         */
        if (!isVisited[i]) {
          if (num[i] != previous[depth]) {
            // Select
            answer[depth] = num[i];
            isVisited[i] = true;
            UpdatePrevious(depth);

            backtracking(depth + 1);

            // Deselect
            isVisited[i] = false;
          }
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