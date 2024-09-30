// 240930 1 #16724
// Class 5
// 01:10
#include <algorithm>
#include <iostream>
#include <vector>
// #define MAX 2147483647
// #define ll long long
using namespace std;

class MY {
  int rowSize, colSize;
  vector<vector<char>> map;
  vector<vector<int>> isVisited;
  int safeZoneCnt = 0;
  int checkCnt = 0;

  pair<int, int> move(const char &input) {
    switch (input) {
    case 'U':
      return {-1, 0};
      break;
    case 'D':
      return {1, 0};
      break;
    case 'L':
      return {0, -1};
      break;
    case 'R':
      return {0, 1};
      break;

    default:
      clog << "err in move";
      return {0, 0};
    }
  }

  void travelLoop(const int &rowStart, const int &colStart) {
    int row = rowStart, col = colStart;

    // Suppose that current loop is a new.
    checkCnt++;

    while (true) {
      isVisited[row][col] = checkCnt;
      pair<int, int> next = move(map[row][col]);
      int rowNext = row + next.first, colNext = col + next.second;

      if (isVisited[rowNext][colNext] != 0) {
        // We are in a new Loop!
        if (isVisited[rowNext][colNext] == checkCnt)
          safeZoneCnt++;

        break;
      }

      // Update row & col to go next
      row = rowNext, col = colNext;
    }
  }

public:
  // MY() {}

  void body() {
    /* Input */
    cin >> rowSize >> colSize; // [,1000]
    map.resize(rowSize, vector<char>(colSize));
    for (int row = 0; row < rowSize; row++)
      for (int col = 0; col < colSize; col++) {
        cin >> map[row][col];
      }

    /* Main */
    isVisited.resize(rowSize, vector<int>(colSize, 0));

    /** Travel the map : O(N^2)
     * 1. Visit every point. pass if it's already visited.
     * 2. do travel starting from [row][col]. make end as a SafeZone.
     * * end: directing where isVisited[][] != 0
     * 3 If what end directs is Safezone, just end the Loop
     * * Else, change the end into Safezone
     */
    for (int row = 0; row < rowSize; row++)
      for (int col = 0; col < colSize; col++) {
        if (isVisited[row][col] == 0)
          travelLoop(row, col);
      }

    cout << safeZoneCnt;
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
