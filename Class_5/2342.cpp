// 240920 1 #2342
// Class 5
// 00:40
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

class my {
  template <typename T> void testArr(T k, bool exitFlag) {
    for (auto e : k)
      clog << e << endl;
    if (exitFlag)
      exit(1);
  }

  vector<int> list;
  vector<vector<pair<int, int>>> DP;
  vector<vector<int>> cost;

  int consumedCost(const int &prev, const int &next) {
    if (prev == next)
      return 1;

    else if (prev == 0)
      return 2;

    else if (abs(prev - next) == 2)
      return 3;

    else
      return 4;
  }

public:
  void body() {
    /* Input */
    while (true) {
      int n;
      cin >> n;
      if (n == 0)
        break;

      list.push_back(n);
    }

    /*
     * Find the Minimum.
     * There is 4 types of moving:
     * 1. cost 1 : (i - > i)
     * 2. cost 2 : (0 <-> i except 0 <-> 0)
     * 4. cost 4 : (1 <-> 3) (2 <-> 4) : delta = 2
     * 3. cost 3 : (1 -> 2,4) (2 -> 1,3) (3 -> 2,4) (4 -> 1,3)

     * Use DP.
     * cost[i][0] is the minimum cost when I push ith button with left foot.
     * cost[i][1] is the minimum cost when I push ith button with right foot.
     * DP[i][0] = the feet location of cost[i][0] {x, y}
     * DP[i][1] = the feet location of cost[i][1] {x, y}

     cost[i][0] = min(cost[i - 1][0] + left, cost[i - 1][1] + right)

     */
    // init
    DP.resize(list.size() + 1, vector<pair<int, int>>(2, {0, 0}));
    cost.resize(list.size() + 1, vector<int>(2, 0));

    /* Main */
    for (int i = 1; i <= list.size(); i++) {
      { // 1. Select ith button with Left
        int prevLeft =
            cost[i - 1][0] + consumedCost(DP[i - 1][0].first, list[i]);
        int prevRight =
            cost[i - 1][1] + consumedCost(DP[i - 1][1].first, list[i]);

        // Update ith tables
        if (prevLeft < prevRight) {
          cost[i][0] = prevLeft;
          DP[i][0] = {list[i], DP[i - 1][0].second};
        } else {
          cost[i][0] = prevRight;
          DP[i][0] = {list[i], DP[i - 1][1].second};
        }
      }

      { // 2. Select ith button with Right
        int prevLeft =
            cost[i - 1][0] + consumedCost(DP[i - 1][0].second, list[i]);
        int prevRight =
            cost[i - 1][1] + consumedCost(DP[i - 1][1].second, list[i]);

        // Update ith tables
        if (prevLeft < prevRight) {
          cost[i][1] = prevLeft;
          DP[i][1] = {DP[i - 1][0].first, list[i]};
        } else {
          cost[i][1] = prevRight;
          DP[i][1] = {DP[i - 1][1].first, list[i]};
        }
      }
    }

    /* Output */
    cout << min(cost[list.size()][0], cost[list.size()][1]);
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
