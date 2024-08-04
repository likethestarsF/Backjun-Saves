// 240804 3 #15652
// Class 4
// 00:
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class my {
  int N, M;

  void backtracking(int depth, vector<int> list) {
    // end of backtracking
    if (depth == M) {
      for (const int &i : list)
        cout << i << ' ';
      cout << '\n';

    } else {
      for (int i = 1; i <= N; i++) {
        // select the elem
        list.push_back(i);
        backtracking(depth + 1, list);
        // deselece the elem
        list.pop_back();
      }
    }
  }

public:
  void body() {
    cin >> N >> M; //[1,8]

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