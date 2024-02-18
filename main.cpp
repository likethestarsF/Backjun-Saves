// 240218 11 #2178
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct coord {
  int row;
  int col;
};

class my {
  vector<vector<bool>> maze;
  coord start = {0, 0};
  coord exit;
  vector<vector<int>> visited;

public:
  void in(const int &length, const int &width) {
    exit = {length - 1, width - 1};

    maze.resize(length, vector<bool>(width, false));
    visited.resize(length, vector<int>(width, 0));

    cin.ignore();
    for (int row = 0; row < length; row++) {
      string line;
      getline(cin, line);
      for (int col = 0; col < width; col++) {
        if (line[col] == '1')
          maze[row][col] = true;
      }
    }
  }

  bool isMovingPossbile(const int &row, const int &col) {
    // 1st. boundary check.
    if (row < 0 || row >= maze.size() || col < 0 || col >= maze[0].size())
      return false;
    // 2nd. is it blocked?
    if (maze[row][col] == false)
      return false;
    // 3rd. is it visited?
    if (visited[row][col] != 0)
      return false;

    return true;
  }

  void travelByBFS() {
    // initiate the queue
    queue<coord> toVisit = {};
    toVisit.push(start);
    visited[0][0] = 1;
    // move: up down left right
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    while (!toVisit.empty()) {
      coord current = toVisit.front();
      toVisit.pop();

      // Exit: when we reach the end point (n,m)
      if (current.row == exit.row && current.col == exit.col)
        break; // while(!queue.empty) exit

      // Pushing phase
      for (int i = 0; i < 4; i++) {
        int rowCord = current.row + dy[i];
        int colCord = current.col + dx[i];

        // push if possible
        if (isMovingPossbile(rowCord, colCord)) {
          toVisit.push({rowCord, colCord});
          visited[rowCord][colCord] = visited[current.row][current.col] + 1;
        }
      } // Pusing End
    }

    // Output
    // cout << '\n' << visited[exit.row][exit.col];
  }

  void test() {
    clog << endl;
    for (const auto &e : maze) {
      for (const auto &f : e) {
        clog << f << " ";
      }
      clog << endl;
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
  int n, m;
  cin >> n >> m;
  a.in(n, m);
  // a.travelByBFS();
  a.test();
}