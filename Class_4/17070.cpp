// 240820 1 #17070
// Class 4
// 00:
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class my {
  int houseSize;
  vector<vector<vector<int>>> house;
  vector<vector<int>> isWall;

  bool isDiagonalPossible(const int &row, const int &col) {
    if (row > 0 && isWall[row - 1][col])
      return false;
    if (col > 0 && isWall[row][col - 1])
      return false;

    return true;
  }

  /**
   * [row][col] = cnt of ways which can reach (row, col)
   * three state: horizontal, vertical, diagonal
   * 0. horizontal
   * h[row][col] = h[row][col-1] + dia[row][col-1]
   * 1. vertical
   * v[row][col] = v[row-1][col] + dia[row][col-1]
   * 2. diagonal
   * dia[row][col] = h[row-1][col-1] + v[-1][-1] + dia[-1][-1]
   */
  int DP(const int &row, const int &col, const int &type) {
    // Boundary Check
    if ((row < 0 || col < 0) || (row >= houseSize || col >= houseSize))
      return 0;

    if (isWall[row][col])
      return 0;

    if (house[row][col][type] == -1)
      switch (type) {
      case 0:
        house[row][col][type] = DP(row, col - 1, 0);
        if (isDiagonalPossible(row, col))
          house[row][col][type] += DP(row, col - 1, 2);
        break;
      case 1:
        house[row][col][type] = DP(row - 1, col, 1);
        if (isDiagonalPossible(row, col))
          house[row][col][type] += DP(row - 1, col, 2);
        break;
      case 2:
        if (isDiagonalPossible(row, col))
          house[row][col][type] = DP(row - 1, col - 1, 0) +
                                  DP(row - 1, col - 1, 1) +
                                  DP(row - 1, col - 1, 2);
        else
          house[row][col][type] = 0;
        break;
      default:
        cerr << "ERROR";
        break;
      }

    // else
    return house[row][col][type];
  }

public:
  void body() {
    /* Input */
    cin >> houseSize; // [3, 16] <= 16*16*16 = 2^12 = 4096
    // 0: horizontal, 1: vertical, 2: diagonal
    house.resize(houseSize,
                 vector<vector<int>>(houseSize, vector<int>(houseSize, -1)));

    isWall.resize(houseSize, vector<int>(houseSize, false));
    for (int row = 0; row < houseSize; row++)
      for (int col = 0; col < houseSize; col++) {
        int temp;
        cin >> temp;
        if (temp == 1)
          isWall[row][col] = true;
      }

    /* Process */
    // initialization
    for (int type = 0; type < 3; type++)
      house[0][0][type] = 0;
    house[0][1][0] = 1;

    // DP
    cout << DP(houseSize - 1, houseSize - 1, 0) +
                DP(houseSize - 1, houseSize - 1, 1) +
                DP(houseSize - 1, houseSize - 1, 2)
         << '\n';
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