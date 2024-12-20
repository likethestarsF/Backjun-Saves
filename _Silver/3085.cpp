// 241220 1 #3085
// Random Marathon 29 H
// 01:00
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
  int answer = 1;

  int checkHorizonal(const int &row) {
    int maxLength = 0;
    for (int start = 0; start < size; start++) {
      const char *cur = &board[row][start];

      int curLength = 1;
      for (int i = start + 1; i < size; i++) {
        if (board[row][i] == *cur)
          curLength++;
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

      int curLength = 1;
      for (int i = start + 1; i < size; i++) {
        if (board[i][col] == *cur)
          curLength++;
        else
          break;
      }

      maxLength = max(maxLength, curLength);
    }

    return maxLength;
  }

  void swapBoard() {
    /**
     * swap
     * check (both horizonal and vertical)
     * restore
     */
    // 1. swap left to right
    for (int r = 0; r < size; r++) {
      for (int c = 0; c < size - 1; c++) {
        swap(board[r][c], board[r][c + 1]);

        for (int row = 0; row < size; row++)
          answer = max(answer, checkVertical(row));
        for (int col = 0; col < size; col++)
          answer = max(answer, checkHorizonal(col));

        swap(board[r][c], board[r][c + 1]);
      }
    }

    // 2. swap up to down
    for (int r = 0; r < size - 1; r++) {
      for (int c = 0; c < size; c++) {
        swap(board[r][c], board[r + 1][c]);

        for (int row = 0; row < size; row++)
          answer = max(answer, checkVertical(row));
        for (int col = 0; col < size; col++)
          answer = max(answer, checkHorizonal(col));

        swap(board[r][c], board[r + 1][c]);
      }
    }
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
    swapBoard();

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
