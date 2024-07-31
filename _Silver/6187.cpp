// 240731 2 #6187
// Random Marthon 9 G
// 00:25
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {
  int weightMax, cowMax;
  vector<int> cows;
  vector<bool> isVisited;
  int max = 0;

  void backtracking(int depth, int weight, int lastIndex) {

    // COND. for termination.
    if (weight > weightMax) {
      max = (max > weight - cows[lastIndex]) ? max : weight - cows[lastIndex];
      return;
    }

    else {
      for (int i = 0; i < cows.size(); i++) {
        if (!isVisited[i]) {
          // select
          isVisited[i] = true;
          backtracking(depth + 1, weight + cows[i], i);
          // deselect
          isVisited[i] = false;
        }
      }
    }
  }

public:
  void body() {
    // Input
    cin >> weightMax; // [100, 5000]
    cin >> cowMax;    // [1, 16]
    cows.resize(cowMax);
    isVisited.resize(cowMax, false);
    for (int i = 0; i < cowMax; i++) {
      cin >> cows[i];
    }

    // Process
    backtracking(0, 0, 0);

    for (int i = 0; i < cows.size(); i++) {
    }

    cout << max;
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