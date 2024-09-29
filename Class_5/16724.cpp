// 240930 1 #16724
// Class 5
// 00:30
#include <algorithm>
#include <iostream>
#include <vector>
// #define MAX 2147483647
// #define ll long long
using namespace std;

class MY {
  int rowSize, colSize;
  int safeZoneCnt = 0;

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

  void travelLoop(const int &rowStart, const int &colStart,
                  vector<vector<char>> &map, vector<vector<bool>> &isVisited) {
    int row = rowStart, col = colStart;
    vector<vector<bool>> isVisitedTemp = isVisited;

    while (true) {
      isVisitedTemp[row][col] = true;
      pair<int, int> next = move(map[row][col]);
      int rowNext = row + next.first, colNext = col + next.second;

      if (isVisitedTemp[rowNext][colNext]) {
        // Add a Safezone only when we reached a new loop
        if (!isVisited[rowNext][colNext]) {
          map[row][col] = 'Z';
          safeZoneCnt++;
        }

        isVisited = isVisitedTemp;
        return;
      }

      // Update row & col
      row = rowNext, col = colNext;
    }
  }

public:
  MY() {}

  void body() {
    /* Input */
    cin >> rowSize >> colSize; // [,1000]
    vector<vector<char>> map(rowSize, vector<char>(colSize));
    for (int row = 0; row < rowSize; row++)
      for (int col = 0; col < colSize; col++) {
        cin >> map[row][col];
      }

    /* Main */
    vector<vector<bool>> isVisited(rowSize, vector<bool>(colSize, false));

    /** Travel the map : O(N^2)
     * 1. Visit every point. pass if it's already visited.
     * 2. do travel starting from [row][col]. make end as a SafeZone.
     * * end: directing where isVisited[][] == true
     * 3 If what end directs is Safezone, just end the Loop
     * * Else, change the end into Safezone

     * 4. Use isVisitedTemp and update original one after the travel,
     * * in order to make a new safe zone only when new loop is started.
     */
    for (int row = 0; row < rowSize; row++)
      for (int col = 0; col < colSize; col++) {
        if (isVisited[row][col])
          continue;

        travelLoop(row, col, map, isVisited);
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
