// 240227 1 #2579
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {
  vector<int> score;
  vector<int> dp;

public:
  void input(int n) {
    score = vector<int>(n);
    dp = vector<int>(n);
    for (int i = 0; i < n; i++) {
      cin >> score[i];
    }
  }

  void body() {
    dp[0] = score[0];
    dp[1] = max(score[0] + score[1], score[1]);
    dp[2] = max(score[0] + score[2], score[1] + score[2]);

    for (int i = 3; i < score.size(); i++) {
      dp[i] = score[i] + max(dp[i - 3] + score[i - 1], dp[i - 2]);
    }

    cout << dp.back();
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
  int n;
  cin >> n;
  a.input(n);
  a.body();
}