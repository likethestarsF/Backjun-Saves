// 240907 1 #2206
// Class 4
// 00:40
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct coord {
  int row, col;
};

class my {
  int rowSize, colSize;

  vector<vector<int>> BFS(const vector<vector<bool>> &isWall,
                          const coord &start) {
    vector<vector<int>> result(rowSize, vector<int>(colSize, -1));

    // init
    result[start.row][start.col] = 0;
    queue<coord> q = {};
    q.push(start);

    while (!q.empty()) {
      coord cur = q.front();
      int curDist = result[cur.row][cur.col];
      q.pop();

      int rowDelta[] = {-1, 0, 1, 0};
      int colDelta[] = {0, -1, 0, 1};
      for (int i = 0; i < 4; i++) {
        int nextRow = cur.row + rowDelta[i];
        int nextCol = cur.col + colDelta[i];

        /**
         * 1. boundary
         * 2. isVisited
         * 3. Update & push : if isWall -> no push
         */
        if (nextRow < 0 || nextRow >= rowSize || nextCol < 0 ||
            nextCol >= colSize)
          continue;
        if (result[nextRow][nextCol] != -1)
          continue;

        // update the dist. map
        result[nextRow][nextCol] = curDist + 1;

        // push only when next is not the wall
        if (!isWall[nextRow][nextCol])
          q.push({nextRow, nextCol});
      }
    }

    return result;
  }

public:
  void body() {
    /* INPUT */
    cin >> rowSize >> colSize; // [1, 1000]
    vector<vector<bool>> isWall(rowSize, vector<bool>(colSize, false));
    for (int row = 0; row < rowSize; row++)
      for (int col = 0; col < colSize; col++) {
        char temp;
        cin >> temp;
        if (temp == '1')
          isWall[row][col] = true;
      }

    coord start = {0, 0};
    coord end = {rowSize - 1, colSize - 1};
    vector<vector<int>> dist_1 = BFS(isWall, start);
    vector<vector<int>> dist_2 = BFS(isWall, end);

    // find Min
    int minDist = 1000 * 1000 * 2; // default
    if (dist_1[end.row][end.col] != -1)
      minDist = dist_1[end.row][end.col];
    for (int row = 0; row < rowSize; row++)
      for (int col = 0; col < colSize; col++) {
        if (!isWall[row][col])
          continue;

        if (dist_1[row][col] != -1 && dist_2[row][col] != -1)
          minDist = min(minDist, dist_1[row][col] + dist_2[row][col]);
      }

    if (minDist != 1000 * 1000 * 2)
      cout << minDist + 1;
    else
      cout << -1;
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
