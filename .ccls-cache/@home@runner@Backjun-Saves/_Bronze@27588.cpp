// 240726 2 #27588
// Random Marthon 8 D
// 00:21
#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

class my {
  int n, m; // [1,50]
  vector<vector<int>> city;

public:
  // two ways of implementing
  // 1. Brute Force Every for grids
  // 2. Find the maximum of point using by divide and conquer : bothersome

  void body() {
    cin >> n >> m;

    city = vector<vector<int>>(n, vector<int>(m));
    for (int row = 0; row < n; row++) {
      for (int col = 0; col < m; col++) {
        cin >> city[row][col]; // [0, 50]
      }
    }

    long int min = 100 * 100 * 2500;

    // selecting points
    for (int rowCurrent = 0; rowCurrent < n; rowCurrent++) {
      for (int colCurrent = 0; colCurrent < m; colCurrent++) {

        // loop for calculate
        long int sum = 0;
        for (int row = 0; row < n; row++) {
          for (int col = 0; col < m; col++) {
            int distance = abs(rowCurrent - row) + abs(colCurrent - col);
            sum += distance * city[row][col];
          }
        }

        if (sum < min)
          min = sum;
      }
    }

    cout << min;
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