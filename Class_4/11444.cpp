// 240928 1 #11444
// Class 4
// 00:20
#include <algorithm>
#include <iostream>
#include <vector>
// #define MAX 2147483647
#define ll long long
using namespace std;

class MY {

  ll fibo(const ll &n) {
    if (n == 0)
      return 0;
    if (n == 1)
      return 1;

    ll prevPrev = 0;
    ll prev = 1;
    ll cur;

    for (int i = 2; i <= n; i++) {
      cur = (prev + prevPrev) % 1000000007;

      // update prevs
      prevPrev = prev;
      prev = cur;
    }
    return cur;
  }

public:
  MY() {}

  void body() {
    /* Input */
    ll input;
    cin >> input; // N[,1e18]

    // O(N)
    cout << fibo(input) % 1000000007;
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  MY my;
  my.body();
}
