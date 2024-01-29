// 240128 5 #11050
#include <iostream>
#include <string>
using namespace std;

int fact(int a) {
  int result;
  (a > 1) ? result = a * fact(a - 1) : result = 1;
  return result;
}

void body() {
  // input
  int n, k;
  cin >> n >> k;

  // process : "n! / (k!(n-k)!)"
  int res;
  res = fact(n) / (fact(k) * fact(n - k));

  // output
  cout << res;
}

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  // cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  body();
}