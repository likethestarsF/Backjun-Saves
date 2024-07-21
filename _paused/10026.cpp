// 240312 2 #10026
// 240321 1 #10026
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

using sh = short;
struct coord {
  sh row, col;
};

class CowArt {
  sh n;
  vector<vector<char>> paint;
  vector<vector<bool>> visited;
  set<coord> seeds = {};

  int numOfArea = 0;

  void spread(queue<coord> &checklist, coord &start) {
    // u d l r
    sh dy[4] = {1, -1, 0, 0};
    sh dx[4] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
      sh y = start.row + dy[i];
      sh x = start.col + dx[i];

      // 1. Boundary Check
      if (y < 0 || y >= n || x < 0 || x >= n)
        continue;

      // 2. visited Check
      if (visited[y][x])
        continue;

      // 3. Paint Check; 3-1: diff, 3-2: same
      if (paint[y][x] != paint[start.row][start.col])
      // 3-1. add the point to seeds.
      {
        coord rowcol = {y, x};
        seeds.insert(rowcol);
      } else
      // 3-2. push it to the queue, update visited.
      {
        checklist.push({y, x});
        visited[y][x] = true;
      }
    }
  }

public:
  CowArt(sh &N) {
    n = N;
    paint.resize(n, vector<char>(n, '0'));
    visited.resize(n, vector<bool>(n, false));
  }

  void input() {
    for (sh row = 0; row < n; row++) {
      for (sh col = 0; col < n; col++) {
        cin >> paint[row][col];
      }
    }
  }

  void body() {
    /*
     * Do coloring from manual start point : (0,0)
     * Repeat coloring until seeds is empty
     * pop the seeds' 1st elem, check if it is visited.
     * 1. If it is, Pass.
     * 2. If it is not, spread from it.
     */
    coord startPoint = {0, 0};
    coloring(startPoint);

    while (!seeds.empty()) {
      coord curCoord = *(seeds.begin());
      seeds.erase(seeds.begin());

      coloring(curCoord);
    }
  }

  void coloring(coord &start) {
    // EXIT: already visited place
    if (visited[start.row][start.col] == true)
      return;

    // init the queue
    queue<coord> checklist = {};
    checklist.push(start);
    visited[start.row][start.col] = true;

    // BFS
    while (!checklist.empty()) {
      coord cur = checklist.front();
      checklist.pop();

      spread(checklist, cur);
    }
    numOfArea++;
  }

  void output() { cout << numOfArea << '\n'; }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  sh N;
  cin >> N;
  CowArt a(N);
  a.input();

  a.body();
  a.output();
}