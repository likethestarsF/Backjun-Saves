// 241220 1 #3085
// Random Marathon 29 H
// 00:20
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
// #define INF 1e8
// #define MAX 2147483647
// #define ll long long
using namespace std;

class MY {
  int size;
  vector<vector<char>> board;
  int answer = 0;

  int checkHorizonal(const int &row) {
    int maxLength = 0;
    for (int start = 0; start < size; start++) {
      const char *cur = &board[row][start];

      // check the prev to optimize
      if (start != 0 && board[row][start - 1] == *cur)
        continue;

      int curLength = 1;

      bool oneCoin = true;
      for (int i = start + 1; i < size; i++) {
        if (board[row][i] == *cur)
          curLength++;

        // swap is possible
        else if (oneCoin) {
          // 1. boundary check and swap adjacents
          if ((row != 0 && board[row - 1][i] == *cur) ||
              (row != size - 1 && board[row + 1][i] == *cur)) {
            curLength++;
            oneCoin = false;
          }

          // 2.jump one candy
          else if (row + 2 < size && board[row + 2][i] == *cur) {
            curLength++;
            break;
          }

          // 3. stop
          else
            break;
        }

        else
          break;
      }
      maxLength = max(maxLength, curLength);
    }

    return maxLength;
  }

  int checkVertical(const int &col) {
    int maxLength = 0;
    for (int start = 0; start < size; start++) {
      const char *cur = &board[start][col];

      // check the prev to optimize
      if (start != 0 && board[start - 1][col] == *cur)
        continue;

      int curLength = 1;

      bool oneCoin = true;
      for (int i = start + 1; i < size; i++) {
        if (board[i][col] == *cur)
          curLength++;

        // swap is possible
        else if (oneCoin) {
          // 1. boundary check and swap adjacents
          if ((col != 0 && board[i][col - 1] == *cur) ||
              (col != size - 1 && board[i][col + 1] == *cur)) {
            curLength++;
            oneCoin = false;
          }

          // 2.jump one candy
          else if (col + 2 < size && board[i][col + 2] == *cur) {
            curLength++;
            break;
          }

          // 3. stop
          else
            break;
        }

        else
          break;
      }
      maxLength = max(maxLength, curLength);
    }

    return maxLength;
  }

public:
  MY() {
    cin >> size; // [3, 50]
    board.resize(size, vector<char>(size));
  }

  void body() {
    /* Input */
    for (int r = 0; r < size; r++)
      for (int c = 0; c < size; c++)
        cin >> board[r][c]; // C P Z Y

    /* Process */
    // starting from [0][0]
    // 1. left to right : one life to check up or down
    // 2. top to bottom : one life to check left or right
    // don't do check if prev was same; do only when the start

    // 1. left to right
    for (int row = 0; row < size; row++)
      answer = max(answer, checkHorizonal(row));
    // 2. up to down
    for (int col = 0; col < size; col++)
      answer = max(answer, checkVertical(col));

    /* Output */
    cout << answer; // maxLength of a line
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  MY my;
  my.body();
}
