// 240812 1 #15686
// Class 4
// 00:50
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 50000000
using namespace std;

struct coord {
  int row, col;
};

class my {
  int cityN, storeN;
  vector<vector<int>> city;
  vector<bool> isSelected;
  vector<coord> storeList = {};
  int result = MAX;

  // Find the Distance between two points
  int FindDist(const coord &a, const coord &b) {
    int row = abs(a.row - b.row);
    int col = abs(a.col - b.col);
    return (row + col);
  }

  // Find the score based on the Selected chicken shops
  int FindScore(const vector<vector<int>> &city, vector<bool> &isSelected) {
    int score = 0;
    for (int row = 0; row < cityN; row++)
      for (int col = 0; col < cityN; col++) {

        if (city[row][col] == 1) {
          int min = MAX;
          for (int i = 0; i < isSelected.size(); i++)
            if (isSelected[i]) {
              min = std::min(min, FindDist({row, col}, storeList[i]));
            }
          score += min;
        }
      }

    return score;
  }

  // Combination for selecting stores
  void backtracking(int depth, int next) {
    // End COND:
    if (depth == storeN) {
      result = min(result, FindScore(city, isSelected));
      return;
    }

    for (int i = next; i < storeList.size(); i++) {
      // select
      if (!isSelected[i]) {
        isSelected[i] = true;

        backtracking(depth + 1, i + 1);

        // deselect
        isSelected[i] = false;
      }
    }
  }

public:
  void body() {
    cin >> cityN >> storeN;
    city.resize(cityN, vector<int>(cityN, 0));
    for (int row = 0; row < cityN; row++)
      for (int col = 0; col < cityN; col++) {
        cin >> city[row][col];

        if (city[row][col] == 2)
          storeList.push_back({row, col});
      }
    isSelected.resize(storeList.size(), false);

    backtracking(0, 0);
    cout << result;
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