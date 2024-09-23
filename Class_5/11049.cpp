// 240923 3 #11049
// Class 5
// 00:40
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 2147483647
using namespace std;

class MY {
  struct mat {
    int row, col;
  };

  int matrixNum;
  vector<mat> matrix;
  vector<vector<int>> dpTable; // [idx1][idx2] = Complexity

  // Top-Down Style
  int dp(const int &idx1, const int &idx2) {
    if (dpTable[idx1][idx2] != -1)
      return dpTable[idx1][idx2];

    if (idx1 == idx2)
      return dpTable[idx1][idx2] = 0;

    // find minimum
    int globalMin = MAX;
    for (int i = idx1; i < idx2; i++) {
      globalMin =
          min(globalMin, dp(idx1, i) + dp(i + 1, idx2) + time(idx1, i, idx2));
    }

    return dpTable[idx1][idx2] = globalMin;
  }

  // time(N*M * M*K) = N*M*K
  int time(const int &a1, const int &a2, const int &b2) {
    int *first = &matrix[a1].row;
    int *second = &matrix[a2].col;
    int *third = &matrix[b2].col;

    return *first * *second * *third;
  }

public:
  MY() {
    /* Input */
    cin >> matrixNum;
    matrix.resize(matrixNum);
    for (int i = 0; i < matrixNum; i++) {
      cin >> matrix[i].row >> matrix[i].col;
    }

    dpTable.resize(matrixNum, vector<int>(matrixNum, -1));
  }

  void body() {

    /**
    * DP should be define where to divide.
    * Time(Main) = Time(sub1) + Time(sub2) + time(sub1 * sub2)

    * Recursive, Top-Down Style
    * for(0 -> end)
    * minMain = min(min , Time(sub) + Time(sub) + time(sub*sub))

    * which args?
    * dpTable[idxStartMat][idxEndMat] = min(Time) -> dp : idx1, idx2
    * time : mat1, mat2
    */

    cout << dp(0, matrixNum - 1);
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
