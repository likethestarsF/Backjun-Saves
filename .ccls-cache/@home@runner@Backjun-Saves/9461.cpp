// 240305 2 #9461
#include <algorithm>
#include <iostream>
#include <vector>
#define DP_SIZE 100
using namespace std;

class my {
  vector<int> DP;

public:
  my() {
    DP.resize(DP_SIZE, 0);
    DP[0] = 1;
    DP[1] = 1;
    DP[2] = 1;
  }

  // An = A(n-2) + A(n-3) (n>=3)
  int answer(const int &target) {
    if (target < 3)
      return DP[target];

    if (DP[target] == 0)
      for (int i = 3; i <= target; i++) {
        DP[i] = DP[i - 2] + DP[i - 3];
      }

    return DP[target];
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
  int t;
  cin >> t;
  while (t--) {
    int target;
    cin >> target;
    cout << a.answer(target - 1) << '\n'; // index starts from 0
  }
}