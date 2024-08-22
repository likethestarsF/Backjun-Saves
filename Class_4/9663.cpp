// 240822 1 #9663
// Class 4
// 01:30
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class my {
  int N;
  vector<int> board;
  int cnt = 0;

  // backtracking
  /**
   * @param board : board[row] = col, also, board[depth] = col
   *
   * COND.
   * Check horizontal, vertical, diagonal directions.
   * 1. horizontal : only 1 queen in a single row.
   * 2. vertical : compare with prev. queens.
   * 3. diagonal : diagonal if |x1-x2| == |y1-y2|
   */
  void NQueen(int depth) {
    if (depth == N) {
      cnt++;
      return;
    }

    for (int col = 0; col < N; col++) {
      // COND.
      bool flag = true;
      for (int prev = 0; prev < depth; prev++) {
        /*COND 1*/

        /*COND 2*/
        if (board[prev] == col) {
          flag = false;
          break;
        }
        /*COND 3*/
        if (abs(prev - depth) == abs(board[prev] - col)) {
          flag = false;
          break;
        }
      }

      if (flag) {
        //  select
        board[depth] = col;

        NQueen(depth + 1);
        // deselect
      }
    }
  }

public:
  void body() {
    /* INPUT */
    cin >> N; // [1,15]

    board.resize(N, -1);
    NQueen(0);
    cout << cnt;
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