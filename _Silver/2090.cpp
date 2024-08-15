// 240815 1 #20909
// Random Marathon 11 F
// 00:00
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class my {
  int n;
  vector<int> num;

  int GCD(const int &a, const int &b) {
    int next;
    int first = max(a, b);
    int second = min(a, b);

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
    int gcd = num[0];
    int lcm = num[0];
    if (n > 1)
      for (int i = 0; i < n - 1; i++) {
        gcd = GCD(lcm, num[i + 1]);
        lcm = lcm * num[i + 1] / gcd;
      }

    int child = 0, mother = lcm;
    // child Sum(lcm / num)
    for (int i = 0; i < n; i++)
      child += lcm / num[i];

    // is it Dividable?
    int div = gcd = GCD(child, mother);
    if (child / div == 1)
      cout << mother / div << '\n';
    else
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