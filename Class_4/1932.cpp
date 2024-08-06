// 240806 6 #1932
// Class 4
// 00:
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {
  int sizeOfTriangle;
  vector<vector<int>> triangle;
  vector<vector<int>> DP;

  int DP_helper(int floor, int index) {
    // There's alreay a value in the DP
    if (DP[floor][index] != -1)
      return DP[floor][index];

    // 3 Exceptional cases
    if (floor == 0) {
      DP[floor][index] = triangle[0][0];
      return DP[floor][index];
    }

    else if (index == 0) {
      DP[floor][index] = triangle[floor][index] + DP_helper(floor - 1, 0);
      return DP[floor][index];
    }

    else if (index == floor) {
      DP[floor][index] =
          triangle[floor][index] + DP_helper(floor - 1, floor - 1);
      return DP[floor][index];
    }

    // General cases
    // Find DP[floor-1][index]
    if (DP[floor - 1][index] == -1)
      DP[floor - 1][index] = DP_helper(floor, index);

    // Find DP[floor-1][index-1]
    if (DP[floor - 1][index - 1] == -1)
      DP[floor - 1][index - 1] = DP_helper(floor, index - 1);

    DP[floor][index] = triangle[floor][index] +
                       max(DP[floor - 1][index], DP[floor - 1][index - 1]);

    return DP[floor][index];
  }

public:
  void body() {
    cin >> sizeOfTriangle; // [1, 500]
    DP.resize(sizeOfTriangle, vector<int>(0));
    triangle.resize(sizeOfTriangle, vector<int>(0));

    // only triangle[i][smaller or equal to i] are available data.
    for (int i = 0; i < sizeOfTriangle; i++) {
      DP[i].resize(i + 1, -1);
      triangle[i].resize(i + 1);
      for (int j = 0; j < i + 1; j++)
        cin >> triangle[i][j]; // [0, 9999]
    }

    // DP
    // DP[floor][ith loc.] = ith value + max of DP[floor -1][ith or i-1th]
    // We need to use top - down style. because bottom-up costs too much time.

    int maxValue = 0;
    // for (int i = 0; i < sizeOfTriangle; i++) {
    //   DP[sizeOfTriangle][i] = DP_helper(sizeOfTriangle, i);
    //   // maxValue = max(maxValue, DP[sizeOfTriangle][i]);
    // }

    cout << maxValue;
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