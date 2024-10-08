// 241008 1 #14500
// Class 3
// 00:30
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
// #define INF 1e8
// #define MAX 2147483647
// #define ll long long
using namespace std;

class MY {
  int rowSize, colSize;

  template <typename T>
  int place(const T &map, const int &row, const int &col) {
    int Max = 0;
    // Block 1
    // 1-1
    if (col + 3 < colSize) {
      int localMax = 0;
      for (int i = 0; i < 4; i++)
        localMax += map[row][col + i];
      Max = max(Max, localMax);
    }
    // 1-2
    if (row + 3 < rowSize) {
      int localMax = 0;
      for (int i = 0; i < 4; i++)
        localMax += map[row + i][col];
      Max = max(Max, localMax);
    }

    // Block 2
    // 2-1
    if (col + 1 < colSize && row + 1 < rowSize) {
      const int dRow[] = {0, 0, 1, 1};
      const int dCol[] = {0, 1, 0, 1};
      int localMax = 0;
      for (int i = 0; i < 4; i++)
        localMax += map[row + dRow[i]][col + dCol[i]];
      Max = max(Max, localMax);
    }

    // Block 3
    // 3-1
    if (row + 2 < rowSize && col + 1 < colSize) {
      const int dRow[] = {0, 1, 2, 2};
      const int dCol[] = {0, 0, 0, 1};
      int localMax = 0;
      for (int i = 0; i < 4; i++)
        localMax += map[row + dRow[i]][col + dCol[i]];
      Max = max(Max, localMax);
    }
    // 3-2
    if (row - 1 >= 0 && col + 2 < colSize) {
      const int dRow[] = {0, 0, 0, -1};
      const int dCol[] = {0, 1, 2, 2};
      int localMax = 0;
      for (int i = 0; i < 4; i++)
        localMax += map[row + dRow[i]][col + dCol[i]];
      Max = max(Max, localMax);
    }
    // 3-3
    if (row + 2 < rowSize && col + 1 < colSize) {
      const int dRow[] = {0, 0, 1, 2};
      const int dCol[] = {0, 1, 1, 1};
      int localMax = 0;
      for (int i = 0; i < 4; i++)
        localMax += map[row + dRow[i]][col + dCol[i]];
      Max = max(Max, localMax);
    }
    // 3-4
    if (row + 1 < rowSize && col + 2 < colSize) {
      const int dRow[] = {0, 1, 0, 0};
      const int dCol[] = {0, 0, 1, 2};
      int localMax = 0;
      for (int i = 0; i < 4; i++)
        localMax += map[row + dRow[i]][col + dCol[i]];
      Max = max(Max, localMax);
    }

    // Block 4
    // 4-1
    if (row + 2 < rowSize && col + 1 < colSize) {
      const int dRow[] = {0, 1, 1, 2};
      const int dCol[] = {0, 0, 1, 1};
      int localMax = 0;
      for (int i = 0; i < 4; i++)
        localMax += map[row + dRow[i]][col + dCol[i]];
      Max = max(Max, localMax);
    }
    // 4-2
    if (row - 1 >= 0 && col + 2 < colSize) {
      const int dRow[] = {0, 0, -1, -1};
      const int dCol[] = {0, 1, 1, 2};
      int localMax = 0;
      for (int i = 0; i < 4; i++)
        localMax += map[row + dRow[i]][col + dCol[i]];
      Max = max(Max, localMax);
    }

    // Block 5
    // 5-1
    if (row + 1 < rowSize && col + 2 < colSize) {
      const int dRow[] = {0, 0, 0, 1};
      const int dCol[] = {0, 1, 2, 1};
      int localMax = 0;
      for (int i = 0; i < 4; i++)
        localMax += map[row + dRow[i]][col + dCol[i]];
      Max = max(Max, localMax);
    }
    // 5-2
    if (row + 2 < rowSize && col + 1 < colSize) {
      const int dRow[] = {0, 1, 2, 1};
      const int dCol[] = {0, 0, 0, 1};
      int localMax = 0;
      for (int i = 0; i < 4; i++)
        localMax += map[row + dRow[i]][col + dCol[i]];
      Max = max(Max, localMax);
    }
    // 5-3
    if (row - 1 >= 0 && col + 2 < colSize) {
      const int dRow[] = {0, 0, 0, -1};
      const int dCol[] = {0, 1, 2, 1};
      int localMax = 0;
      for (int i = 0; i < 4; i++)
        localMax += map[row + dRow[i]][col + dCol[i]];
      Max = max(Max, localMax);
    }
    // 5-4
    if (row + 2 < rowSize && col - 1 >= 0) {
      const int dRow[] = {0, 1, 2, 1};
      const int dCol[] = {0, 0, 0, -1};
      int localMax = 0;
      for (int i = 0; i < 4; i++)
        localMax += map[row + dRow[i]][col + dCol[i]];
      Max = max(Max, localMax);
    }

    // Block 3-Flip
    // 3-1
    if (row + 2 < rowSize && col - 1 >= 0) {
      const int dRow[] = {0, 1, 2, 2};
      const int dCol[] = {0, 0, 0, -1};
      int localMax = 0;
      for (int i = 0; i < 4; i++)
        localMax += map[row + dRow[i]][col + dCol[i]];
      Max = max(Max, localMax);
    }
    // 3-2
    if (row + 1 < rowSize && col + 2 < colSize) {
      const int dRow[] = {0, 0, 0, 1};
      const int dCol[] = {0, 1, 2, 2};
      int localMax = 0;
      for (int i = 0; i < 4; i++)
        localMax += map[row + dRow[i]][col + dCol[i]];
      Max = max(Max, localMax);
    }
    // 3-3
    if (row + 2 < rowSize && col + 1 < colSize) {
      const int dRow[] = {0, 0, 1, 2};
      const int dCol[] = {0, 1, 0, 0};
      int localMax = 0;
      for (int i = 0; i < 4; i++)
        localMax += map[row + dRow[i]][col + dCol[i]];
      Max = max(Max, localMax);
    }
    // 3-4
    if (row + 1 < rowSize && col + 2 < colSize) {
      const int dRow[] = {0, 1, 1, 1};
      const int dCol[] = {0, 0, 1, 2};
      int localMax = 0;
      for (int i = 0; i < 4; i++)
        localMax += map[row + dRow[i]][col + dCol[i]];
      Max = max(Max, localMax);
    }

    // Block 4-Flip
    // 4-1
    if (row + 2 < rowSize && col - 1 >= 0) {
      const int dRow[] = {0, 1, 1, 2};
      const int dCol[] = {0, 0, -1, -1};
      int localMax = 0;
      for (int i = 0; i < 4; i++)
        localMax += map[row + dRow[i]][col + dCol[i]];
      Max = max(Max, localMax);
    }
    // 4-2
    if (row + 1 < rowSize && col + 2 < colSize) {
      const int dRow[] = {0, 0, 1, 1};
      const int dCol[] = {0, 1, 1, 2};
      int localMax = 0;
      for (int i = 0; i < 4; i++)
        localMax += map[row + dRow[i]][col + dCol[i]];
      Max = max(Max, localMax);
    }

    return Max;
  }

public:
  // MY() {}

  void body() {
    cin >> rowSize >> colSize; // [4,500]
    vector<vector<int>> input(rowSize, vector<int>(colSize));

    /* input */
    for (int row = 0; row < rowSize; row++)
      for (int col = 0; col < colSize; col++)
        cin >> input[row][col]; // (,1e3)

    /** Brute Force
     * 2 + 1 + 4 + 2 + 4 + (4 + 2)= 13 + 6 cases
     */

    int globalMax = 0; // < 25e4*1e3 = 25e7
    for (int row = 0; row < rowSize; row++)
      for (int col = 0; col < colSize; col++)
        globalMax = std::max(globalMax, place(input, row, col));

    cout << globalMax;
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
