// 240806 4 #1149
// Class 4
// 00:
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {
  int nOfHouses;
  vector<vector<int>> houses; // houses[ith][RGB]
  vector<vector<int>> DP;

  int CheapestResult(int i) { return min(DP[i][0], min(DP[i][1], DP[i][2])); }

  int MinOfPrevious(int index, int color) {
    int result = 1001;
    for (int j = 0; j < 3; j++) {
      if (j != color)
        result = min(result, DP[index][j]);
    }
    return result;
  }

public:
  void body() {
    cin >> nOfHouses; // [1, 1000]
    houses.resize(nOfHouses, vector<int>(3, 0));
    for (int i = 0; i < nOfHouses; i++)
      for (int j = 0; j < 3; j++)
        cin >> houses[i][j]; // [1, 1000]

    /*
     Rule 1. Color of 1st house != that of 2nd
     Rule 2. that of Nth != that of (N-1)th
     Rule 3. that of (i)th != that of both (i-1)th and (i+1)th ;
     i~[2, N-1] Find the min. cost
    */

    /*
     DP[House][RGB]
     DP[i][x] means the min value when i is colored with the x.
     DP[i][x] = houses[x] + min of DP[i - 1][!x]
     Top-down style implementation
    */

    DP.resize(nOfHouses, vector<int>(3, 0)); // MAX = 1000 * 3
    for (int i = 0; i < 3; i++)
      DP[0][i] = houses[0][i];

    for (int i = 1; i < nOfHouses; i++) {
      for (int j = 0; j < 3; j++)
        DP[i][j] = houses[i][j] + MinOfPrevious(i - 1, j);
    }

    cout << CheapestResult(nOfHouses - 1);
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