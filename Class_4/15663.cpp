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
  void backtracking(int depth) {
    // Exit
    if (depth == M) {
      if (previous != answer) {

        for (const int &elem : answer)
          cout << elem << ' ';
        cout << '\n';

        previous = answer;
      }
    }

    else {
      for (int i = 0; i < N; i++) {
        // Select
        answer[depth] = num[i];

        backtracking(depth + 1);

        // Deselect
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