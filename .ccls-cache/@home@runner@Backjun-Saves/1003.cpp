// 240211 9 #1003
// 240212 1 #1003
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int fibonacciREF(int n) {
  if (n == 0) {
    printf("0");
    return 0;
  } else if (n == 1) {
    printf("1");
    return 1;
  } else {
    return fibonacciREF(n - 1) + fibonacciREF(n - 2);
  }
}

struct two {
  int cnt0 = -1;
  int cnt1 = -1;
};

two operator+(const two &a1, const two &a2) {
  return {a1.cnt0 + a2.cnt0, a1.cnt1 + a2.cnt1};
}

class fibonacci {
  vector<two> dp;
  two answer = {-1, -1};

public:
  fibonacci(int t) {
    while (t--) {
      int num;
      cin >> num;
      dp = vector<two>(num + 1);

      answer = recall(num);
      output();
    }
  }

  /* DP logics
  ** Do not return itself if n is exist in dp table.
  ** dp returns two data.
  */
  two recall(const int n) {
    if (dp[n].cnt0 == -1) {
      if (n == 0) {
        return {1, 0};
      } else if (n == 1) {
        return {0, 1};
      } else {
        dp[n] = recall(n - 1) + recall(n - 2);
        return dp[n];
      }
    } else {
      return dp[n];
    }
  }

  void output() { cout << answer.cnt0 << ' ' << answer.cnt1 << '\n'; }
};

void body() {
  // input
  int t;
  cin >> t;

  //  process
  fibonacci f(t);

  // output
}

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  body();
}