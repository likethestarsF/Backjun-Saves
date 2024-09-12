// 240911 2 #2239
// 240912 1 #2239
// Class 5
// 01:00
#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 200000
using namespace std;

class my {
  vector<vector<int>> sudoku_origin; // 9*9

  /**
   * SUDOKU
   * Guess A(x,y) is selected.
   * 1. it should not be a num in the same row: x
   * 2. it should not be a num in the same col: y
   * 3. it should not be a num in the same 3*3 block: 9 cases
   */

  vector<bool> CheckCond(const vector<vector<int>> &sudoku, const int &x,
                         const int &y) {
    vector<bool> isPossible(10, true);
    for (int i = 0; i < 9; i++) {
      isPossible[sudoku[i][y]] = false; // 1
      isPossible[sudoku[x][i]] = false; // 2
    }
    // 3
    // 3-1. deifne the block
    int block_start_row = (x / 3) * 3;
    int block_start_col = (y / 3) * 3;

    // 3-2. update marker
    for (int row = block_start_row; row < block_start_row + 3; ++row)
      for (int col = block_start_col; col < block_start_col + 3; ++col)
        isPossible[sudoku[row][col]] = false;

    return isPossible;
  }

  bool Backtracking(vector<vector<int>> &sudoku, const int &depth) {

    for (int row = 0; row < 9; row++)
      for (int col = 0; col < 9; col++) {
        // COND.
        if (sudoku[row][col] != 0)
          continue;

        const vector<bool> isPossible = CheckCond(sudoku, row, col);
        for (int i = 1; i <= 9; i++) {
          if (isPossible[i]) {
            // select
            sudoku[row][col] = i;

            if (Backtracking(sudoku, depth + 1))
              return true;

            // deselect
            sudoku[row][col] = 0;
          }
        }

        return false;
      }

    return true; // All cells are filled correctly
  }

public:
  void body() {
    /* INPUT */
    sudoku_origin.resize(9, vector<int>(9, 0));
    int cnt = 0;
    for (int row = 0; row < 9; row++)
      for (int col = 0; col < 9; col++) {
        char tmpInput;
        cin >> tmpInput;
        sudoku_origin[row][col] = tmpInput - '0';
      }

    int depth = 81 - cnt;
    Backtracking(sudoku_origin, depth);

    /* OUTPUT */
    for (int row = 0; row < 9; row++) {
      for (int col = 0; col < 9; col++) {
        cout << sudoku_origin[row][col];
      }
      cout << '\n';
    }
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