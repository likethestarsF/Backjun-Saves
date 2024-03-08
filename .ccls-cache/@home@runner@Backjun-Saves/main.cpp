// 240308 3 #21736
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct coord {
  int x, y;
};

class findFriends {
  vector<vector<bool>> campus = {};
  vector<vector<bool>> visited{};
  int row, col;

  coord start;
  vector<coord> friends = {};
  vector<coord> block = {};

  int numOfMet = 0;

  void pushing(queue<coord> &toPush, coord &a) {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++) {
      int newX = a.x + dx[i];
      int newY = a.y + dy[i];
      // 1. Boundary Check - Exclude
      if (newX < 0 || newX >= col || newY < 0 || newY >= row)
        continue;

      // 2. is it visited? - Exclude
      if (visited[newY][newX] == true)
        continue;

      // push the new coord to the queue & update
      toPush.push({newX, newY});
      visited[newY][newX] = true;
    }
  }

public:
  findFriends(int &n, int &m) {
    row = n;
    col = m;
    campus.resize(row, vector<bool>(col, false));
    visited.resize(row, vector<bool>(col, false));
  }

  /*
  ** O == empty  : 0  ; visited : 0
  ** P == friend : 1  ; visited : 0
  ** X == block  : 0  ; visited : 1
  ** I == start  : 0  ; visited : 1
  */
  void input() {
    for (int y = 0; y < row; y++) {
      for (int x = 0; x < col; x++) {
        char c;
        cin >> c;
        if (c == 'P') {
          friends.push_back({x, y});
          campus[y][x] = true;

        } else if (c == 'X') {
          block.push_back({x, y});
          visited[y][x] = true;

        } else if (c == 'I') {
          start = {x, y};
          visited[y][x] = true;
        }
      }
    }
  }

  void BFS() {
    queue<coord> check = {};
    // init the queue by start
    pushing(check, start);

    while (!check.empty()) {
      coord cur = check.front();
      check.pop();

      // count the num of met friends
      if (campus[cur.y][cur.x] == true)
        numOfMet++;

      pushing(check, cur);
    }
  }

  void output() {
    if (numOfMet == 0)
      cout << "TT";
    else
      cout << numOfMet;
  }
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
  findFriends a(n, m);
  a.input();
  a.BFS();
  a.output();
}