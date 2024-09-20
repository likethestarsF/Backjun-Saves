// 240920 1 #2342
// Class 5
// 02:40
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define INF 1e6
using namespace std;

class my {
  template <typename T> void testArr(T k, bool exitFlag) {
    for (auto e : k)
      clog << e << endl;
    if (exitFlag)
      exit(1);
  }

  vector<int> step;
  vector<vector<vector<int>>> dpTable;

  int moveCost(const int &prev, const int &next) {
    if (prev == next)
      return 1;
    if (prev == 0)
      return 2;
    if (abs(prev - next) == 2)
      return 4;
    return 3;
  }

  int dp(int depth, int left, int right) {
    if (depth == step.size())
      return 0; // exit
    if (left != 0 && (left == right))
      return INF; // impossible case

    if (dpTable[depth][left][right] != INF)
      return dpTable[depth][left][right]; // already existed

    int nextStep = step[depth];
    // move Left foot
    int moveL = dp(depth + 1, nextStep, right) + moveCost(left, nextStep);
    // move Right foot
    int moveR = dp(depth + 1, left, nextStep) + moveCost(right, nextStep);

    return dpTable[depth][left][right] = min(moveL, moveR);
  }

public:
  void body() {
    /* Input */
    while (true) {
      int n;
      cin >> n;
      if (n == 0)
        break;

      step.push_back(n);
    }

    /* Main */
    dpTable.resize(step.size(), vector<vector<int>>(5, vector<int>(5, INF)));
    int result = dp(0, 0, 0);

    /* Output */
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
