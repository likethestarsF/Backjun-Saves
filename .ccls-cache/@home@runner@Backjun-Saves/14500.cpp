// 240329 1 #14500
#include <algorithm>
#include <iostream>
#include <vector>
#define MAX_NUMBER 1000
using namespace std;

struct coord {
  vector<int> row, col;
};

class tetromino {
  int row, col;
  vector<vector<int>> paper;
  vector<vector<bool>> paperVisited;

public:
  tetromino(int n, int m) {
    row = n, col = m;
    paper.resize(row, vector<int>(col, 0));
    paperVisited.resize(row, vector<bool>(col, false));

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        cin >> paper[i][j];
      }
    }
  }

  /* loop for every point
   * adjacent is added on list
   * find biggest in list
   * it becomes a part of tetro
   * again add the adjacent points
   */
  void body() {
    // paper[i][j]
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (paperVisited[i][j] == true)
          continue;

        vector<coord> adjacent;
        adjacent.resize(MAX_NUMBER);
        int max;
        int sum = 0;

        // init
        // add nearby 4 points
        addNearby(adjacent, i, j);
      }
    }
  }

  template <typename T> void addNearby(T &adjacent, int &row, int &col) {
    int drow[4] = {1, -1, 0, 0};
    int dcol[4] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++) {
      int newRow = row + drow[i];
      int newCol = col + dcol[i];
      // 1. Boundary
      if (newRow < 0 || newRow >= row || newCol < 0 || newCol >= col)
        continue;
      // 2. Is  not a part of tetro
      if (paperVisited[newRow][newCol] == true)
    }
  }

  // O(NM * )
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  int n, m;
  cin >> n >> m;
  tetromino a(n, m);
}