// 240731 1 #2992
// Random Marthon 9 H
// 01:15
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {

public:
  string X;
  string min = "1000000";

  vector<bool> isVisited = {};
  vector<char> pool = {};
  vector<char> result = {};

  void updateMax(vector<char> &pool) {
    string target = {};
    for (const auto &i : pool) {
      target += i;
    }

    if (stoi(target) <= stoi(X))
      return;

    min = (stoi(target) > stoi(min)) ? min : target;
  }

  void backtracking(int depth) {
    // 1. Calc. the result when reached the end
    if (depth == X.length()) {
      updateMax(result);

      return;
    }

    // 2. Choose the elem.
    else {
      for (int cur = 0; cur < X.length(); cur++) {
        if (!isVisited[cur]) {
          // Select the elem.
          isVisited[cur] = true;
          result[depth] = pool[cur];

          // Recall the backtracking
          backtracking(depth + 1);

          // deselct the elem.
          isVisited[cur] = false;
        }
      }
    }
  }

  void body() {
    cin >> X; // [1, 999999] -> 6! = 720
    for (const char &c : X)
      pool.push_back(c);
    result.resize(pool.size());

    // Use backtracking.
    isVisited.resize(pool.size(), false);
    backtracking(0);

    // Output
    if (min == "1000000")
      cout << 0;
    else
      cout << stoi(min);
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