// 240218 12 #2667
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
  vector<vector<bool>> town;    // constant
  vector<vector<bool>> visited; // updated
  vector<int> numHouses = {};

public:
  void in(const int &length) {

    town.resize(length, vector<bool>(length, false));
    visited.resize(length, vector<bool>(length, 0));

    cin.ignore();
    for (int row = 0; row < length; row++) {
      string line;
      getline(cin, line);
      for (int col = 0; col < length; col++) {
        if (line[col] == '1')
          town[row][col] = true;
      }
    }
  }

  bool isMovingPossbile(const int &row, const int &col) {
    // 1st. boundary check.
    if (row < 0 || row >= town.size() || col < 0 || col >= town[0].size())
      return false;
    // 2nd. is it blocked?
    if (town[row][col] == false)
      return false;
    // 3rd. is it visited?
    if (visited[row][col] != false)
      return false;

    return true;
  }

  coord findStart() {
    coord start = {-1, -1};

    for (int row = 0; row < town.size(); row++) {
      for (int col = 0; col < town.size(); col++) {
        if (town[row][col] == true && visited[row][col] == false) {
          start = {row, col};
          goto EXIT;
        }
      }
    }

  EXIT:
    return start;
  }

  void examineTown() {
    while (true) {
      coord start = findStart();
      if (start.row == -1 && start.col == -1)
        break; // Only exit: while(true); No more Village in town to examine.

      travelByBFS(start);
    }

    // output
    sort(numHouses.begin(), numHouses.end());
    cout << numHouses.size() << '\n';
    for (const auto &elem : numHouses)
      cout << elem << '\n';
  }

  void travelByBFS(const coord &start) {
    int houseCnt = 0; // update whenever do push

    // initiate the queue
    queue<coord> toVisit = {};
    toVisit.push(start);
    houseCnt++;
    visited[start.row][start.col] = true;

    // move: up down left right
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    // Exit: only when we can not find any houses to visit; while COND.
    while (!toVisit.empty()) {
      coord current = toVisit.front();
      toVisit.pop();

      // Pushing phase
      for (int i = 0; i < 4; i++) {
        int rowCord = current.row + dy[i];
        int colCord = current.col + dx[i];

        // push if possible
        if (isMovingPossbile(rowCord, colCord)) {
          toVisit.push({rowCord, colCord});
          houseCnt++;
          visited[rowCord][colCord] = visited[current.row][current.col] + 1;
        }
      } // Pusing End
    }

    // save the cnt to numHouses
    numHouses.push_back(houseCnt);
  }

  void test() {
    clog << endl;
    for (const auto &e : town) {
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
  int n;
  cin >> n;
  a.in(n);
  a.examineTown();
  // a.test();
}