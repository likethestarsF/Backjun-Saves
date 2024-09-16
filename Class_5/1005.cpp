// 240916 1 #1005
// Class 5
// 00:30
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define MAX 200000000
using namespace std;

class my {
  int buildN, ruleN;
  vector<int> time;
  vector<int> sumTime;
  vector<vector<int>> order; // order[a] = {b,c,d}; b,c,d are built before a.
  int target;

  int Time(const int &target) {
    const vector<int> parents = order[target];

    // Use DP for the time performance
    if (sumTime[target] != -1)
      return sumTime[target];

    // When there's no parent
    if (parents.empty())
      return sumTime[target] = time[target];

    // general cases
    int maxOfParents = 0;
    for (const int &idx : parents) {
      maxOfParents = max(maxOfParents, Time(idx));
    }

    // return the maximum time; every required construction is finished
    return sumTime[target] = (time[target] + maxOfParents);
  }

public:
  void body() {
    /* Input */
    cin >> buildN >> ruleN; // [2, 1000], [1, 100000]

    time.resize(buildN);
    for (int i = 0; i < buildN; i++)
      cin >> time[i]; // [0, 100000]
    sumTime.resize(buildN, -1);

    order.resize(buildN, vector<int>(0));
    for (int i = 0; i < ruleN; i++) {
      int root, child;
      cin >> root >> child;
      root--, child--;
      order[child].push_back(root);
    }

    cin >> target;
    target--;

    /**
     * time of K = max(time of parents of K) + time of K
     * : a, b -> c; time(c) = max(time(a), time(b)) + time[c]
     */
    Time(target);

    /* Output */
    cout << sumTime[target] << '\n';
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  int test;
  cin >> test;
  while (test--) {
    my a;
    a.body();
  }
}
