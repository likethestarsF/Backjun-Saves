// 240815 1 #2090
// Random Marathon 11 F
// 00:30
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define ll long long

class my {
  ll int n;
  vector<ll int> num;

  ll int GCD(const ll int &a, const ll int &b) {
    ll int next;
    ll int first = max(a, b);
    ll int second = min(a, b);

    while (first % second > 0) {
      next = first % second;
      first = second;
      second = next;
    }

    return second;
  }

public:
  void body() {
    cin >> n;
    num.resize(n);
    for (int i = 0; i < n; i++)
      cin >> num[i]; // [1, 100]

    // find LCM of num
    ll int gcd = num[0];
    ll int lcm = num[0];
    if (n > 1)
      for (int i = 0; i < n - 1; i++) {
        gcd = GCD(lcm, num[i + 1]);
        lcm = lcm * num[i + 1] / gcd;
      }

    ll int child = 0, mother = lcm;
    // child Sum(lcm / num)
    for (ll int i = 0; i < n; i++)
      child += lcm / num[i];

    // is it Dividable?
    ll int div = gcd = GCD(child, mother);
    cout << mother / div << '/' << child / div << '\n';
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