// 241005 1 #16946
// Class 5
// 01:00
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
// #define INF 1e8
// #define MAX 2147483647
// #define ll long long
using namespace std;

const int dRow[] = {0, 0, -1, 1};
const int dCol[] = {-1, 1, 0, 0};

class MY {
  struct coord {
    int row, col;
  };
  int rowSize, colSize;
  vector<vector<bool>> isWall;
  vector<vector<int>> map;
  vector<int> value;

  void BFS(const int &rowStart, const int &colStart, const int &label) {
    queue<coord> q;

    q.push({rowStart, colStart});
    map[rowStart][colStart] = label;
    int cnt = 1;

    while (!q.empty()) {
      const coord cur = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        const int rowNext = cur.row + dRow[i];
        const int colNext = cur.col + dCol[i];

        // boundary check
        if (rowNext < 0 || rowNext >= rowSize || colNext < 0 ||
            colNext >= colSize)
          continue;

        if (map[rowNext][colNext] == -1) {
          map[rowNext][colNext] = label;
          q.push({rowNext, colNext});
          cnt++;
        }
      }
    }

    value.push_back(cnt % 10);
  }

  int calcAnswer(const int &rowStart, const int &colStart) {
    int sum = 1; // +1 itself
    set<int> labels = {};

    for (int i = 0; i < 4; i++) {
      const int rowNext = rowStart + dRow[i];
      const int colNext = colStart + dCol[i];

      // boundary check
      if (rowNext < 0 || rowNext >= rowSize || colNext < 0 ||
          colNext >= colSize)
        continue;

      labels.insert(map[rowNext][colNext]);
    }

    for (set<int>::iterator it = labels.begin(); it != labels.end(); it++)
      sum += value[*it];

    return sum % 10;
  }

public:
  MY() {
    cin >> rowSize >> colSize; // [,1e3]
    isWall.resize(rowSize, vector<bool>(colSize, false));

    // vector for 1. stage. : unvisited = -1, Wall = 0, else = label idx
    map.resize(rowSize, vector<int>(colSize, -1));
    value.resize(1, 0); // 0 isn't used
  }

  void body() {

    /* Input */
    for (int row = 0; row < rowSize; row++)
      for (int col = 0; col < colSize; col++) {
        char input;
        cin >> input;
        if (input == '1') {
          isWall[row][col] = true;
          map[row][col] = 0;
        }
      }

    /** BFS
     * 1. do BFS from every 0
     * 1-1. Label a connected group(0) of map by unique (int)idx=[,1e6]
     * 1-2. Save the number of places of the group in vector[idx]
     * 2. Find the Answer,
     * * answer[Wall] = SUM(adjacent 0's values in the vector[idx]) + 1
     * * + 1 because the '1' itself is counted
     * * do % 10.
     * 3. BFS at every Wall may cause timeout.
     */

    // 1. O(N^2)
    int labelIdx = 1;
    for (int row = 0; row < rowSize; row++)
      for (int col = 0; col < colSize; col++) {
        if (map[row][col] == -1)
          BFS(row, col, labelIdx++);
      }

    // 2. + Output
    for (int row = 0; row < rowSize; row++) {

      for (int col = 0; col < colSize; col++) {
        if (!isWall[row][col])
          cout << 0;

        else
          cout << calcAnswer(row, col);
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

  MY my;
  my.body();
}
