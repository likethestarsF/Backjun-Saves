// 240819 1 #1987
// Class 4
// 00:25
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class my {
  int rowSize, colSize, Max = 1;
  vector<vector<char>> board;
  vector<bool> isVisited; // 26. -'A'.

  void backtracking(int depth, const int &row, const int &col) {
    Max = max(depth, Max); // update Max everytime
    /** the end of the loop.
     * 1. out of bound
     * 2. every nearby places are visited
     */

    // order: left right up down
    int deltaRow[4] = {0, 0, -1, 1};
    int deltaCol[4] = {-1, 1, 0, 0};

    for (int i = 0; i < 4; i++) {
      int nextRow = row + deltaRow[i];
      int nextCol = col + deltaCol[i];

      if (nextRow < 0 || nextRow >= rowSize || nextCol < 0 ||
          nextCol >= colSize)
        continue;
      if (isVisited[board[nextRow][nextCol] - 'A'])
        continue;

      // select
      isVisited[board[nextRow][nextCol] - 'A'] = true;

      backtracking(depth + 1, nextRow, nextCol);
      // deselect
      isVisited[board[nextRow][nextCol] - 'A'] = false;
    }
  }

public:
  void body() {
    /* Input */
    cin >> rowSize >> colSize; // [1, 20]
    board.resize(rowSize, vector<char>(colSize));
    for (int row = 0; row < rowSize; row++)
      for (int col = 0; col < colSize; col++) {
        cin >> board[row][col]; // [0, 100]
      }

    /* Main */
    isVisited.resize(26, false);
    isVisited[board[0][0] - 'A'] = true;
    backtracking(1, 0, 0);
    cout << Max;
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