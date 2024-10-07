// 241007 1 #10026
// Class 3
// 00:20
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
// #define INF 1e8
// #define MAX 2147483647
// #define ll long long
using namespace std;

const int dRow[] = {0, 0, 1, -1};
const int dCol[] = {1, -1, 0, 0};

class MY {
  enum Color {
    Red,
    Green,
    Blue,
  };
  struct coord {
    int row, col;
  };

  int size;
  vector<vector<Color>> img;

  int BFS() {
    vector<vector<bool>> isVisited(size, vector<bool>(size, false));
    int cnt = 0;

    for (int row = 0; row < size; row++)
      for (int col = 0; col < size; col++) {
        if (isVisited[row][col])
          continue;

        cnt++;
        queue<coord> q;
        q.push({row, col});
        isVisited[row][col] = true;

        while (!q.empty()) {
          const coord cur = q.front();
          q.pop();

          for (int i = 0; i < 4; i++) {
            const int nextRow = cur.row + dRow[i];
            const int nextCol = cur.col + dCol[i];

            // boundary check
            if (nextRow < 0 || nextRow >= size || nextCol < 0 ||
                nextCol >= size)
              continue;

            if (isVisited[nextRow][nextCol])
              continue;

            if (img[nextRow][nextCol] == img[cur.row][cur.col]) {
              q.push({nextRow, nextCol});
              isVisited[nextRow][nextCol] = true;
            }
          }
        }
      }

    return cnt;
  }

  int modifiedBFS() {
    vector<vector<bool>> isVisited(size, vector<bool>(size, false));
    int cnt = 0;

    for (int row = 0; row < size; row++)
      for (int col = 0; col < size; col++) {
        if (isVisited[row][col])
          continue;

        cnt++;
        queue<coord> q;
        q.push({row, col});
        isVisited[row][col] = true;

        while (!q.empty()) {
          const coord cur = q.front();
          q.pop();

          for (int i = 0; i < 4; i++) {
            const int nextRow = cur.row + dRow[i];
            const int nextCol = cur.col + dCol[i];

            // boundary check
            if (nextRow < 0 || nextRow >= size || nextCol < 0 ||
                nextCol >= size)
              continue;
            if (isVisited[nextRow][nextCol])
              continue;

            if (img[cur.row][cur.col] == Blue) {
              if (img[nextRow][nextCol] == img[cur.row][cur.col]) {
                q.push({nextRow, nextCol});
                isVisited[nextRow][nextCol] = true;
              }
            }

            else {
              if (img[nextRow][nextCol] != Blue) {
                q.push({nextRow, nextCol});
                isVisited[nextRow][nextCol] = true;
              }
            }
          }
        }
      }

    return cnt;
  }

public:
  MY() {
    cin >> size; // [,100]
    img.resize(size, vector<Color>(size));
  }

  void body() {
    /* Input */
    for (int row = 0; row < size; row++)
      for (int col = 0; col < size; col++) {
        char input;
        cin >> input;
        if (input == 'R')
          img[row][col] = Red;
        else if (input == 'G')
          img[row][col] = Green;
        else if (input == 'B')
          img[row][col] = Blue;
      }

    /** BFS
     * 1. label each groups by BFS
     * 2. label once more R=G
     * >> This would probably be a timeout case.
     */

    cout << BFS() << ' ';
    cout << modifiedBFS();
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
