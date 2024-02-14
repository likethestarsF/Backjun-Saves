// 2402014 5 #7576
// per day, tomato becomes ripe
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class box {
  int width, length;
  vector<vector<int>> tomato;
  vector<pair<int, int>> tomatoRipe;
  // vector<pair<int, int>> tomatoNone;
  int dayCnt = 0;
  int ripeCnt = 0;
  int noneCnt = 0;
  int totalTomato;

public:
  box() {
    cin >> width >> length;
    tomato = vector<vector<int>>(length, vector<int>(width));
  }

  void input() {
    for (int i = 0; i < length; i++) {
      for (int j = 0; j < width; j++) {
        int a;
        cin >> a;
        tomato[i][j] = a;
        if (a == 1) {
          tomatoRipe.push_back({i, j});
          ripeCnt++;
        } else if (a == -1) {
          // tomatoNone.push_back({i, j});
          noneCnt++;
        }
      }
    }

    // when we reach this number. everything is ripe
    totalTomato = width * length - noneCnt;
  }

  bool nonRipeExist() { return ripeCnt != totalTomato; }

  void process() {
    // BFS
    while (!tomatoRipe.empty()) {
      // day goes:
      // 1. make the list for tomatoes about to ripen
      queue<pair<int, int>> checklist = {};

      // **check the ripe tomatoes
      // tomatoRipe is temporary. tomatoRipe will be cleared
      for (const auto &elem : tomatoRipe) {
        // push for 4-direction without check : this list is temporary.
        checklist.push({elem.first, elem.second - 1}); // left
        checklist.push({elem.first, elem.second + 1}); // right
        checklist.push({elem.first - 1, elem.second}); // back
        checklist.push({elem.first + 1, elem.second}); // front
      }
      tomatoRipe.clear();

      // 4-direction check requires: in boundary, no ripe, no none place
      while (!checklist.empty()) {
        int iT = checklist.front().first;
        int jT = checklist.front().second;
        checklist.pop();

        if (iT >= 0 && iT < length && jT >= 0 && jT < width) {
          if (tomato[iT][jT] == 0) {
            // it is available to ripe
            tomatoRipe.push_back({iT, jT});
            tomato[iT][jT] = 1;
            ripeCnt++;
          }
        }
      }
      // days are gone
      dayCnt++;
    }
    dayCnt--;

    // impossible case:
    if (nonRipeExist()) {
      dayCnt = -1;
    }
  }

  void output() { cout << dayCnt; }

  void test_tomato() {
    for (int i = 0; i < length; i++) {
      for (int j = 0; j < width; j++) {
        cout << tomato[i][j] << " ";
      }
      cout << endl; // Move to the next row
    }
  }

  void test_tomatoRipe() {
    for (const auto &elem : tomatoRipe)
      cout << elem.first << " " << elem.second << endl;
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  box a;
  a.input();
  // a.test_tomatoRipe();
  a.process();
  a.output();
}