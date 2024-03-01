// 240229 3 #6064
// 240301 1 #6064
/* 1. If <M:N> represents the lastest year of Cain calendar,
** find XX : <x:y> is the XXth year.
** 2. If <x:y> is invalid expression, return -1.
** M, N | [1, 40000]
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Euclidean(int a, int b) {
  int r = a % b;
  if (r == 0) {
    return b;
  }
  return Euclidean(b, r);
}

class my {
  int M, N, x, y;

public:
  void input() { cin >> M >> N >> x >> y; }

  int yearCalculator() {
    // criteria : x
    int xVar, yVar;
    const int lcm = M * (N / Euclidean(M, N));

    for (int i = 0;; i++) {
      xVar = x + M * i;
      yVar = xVar % N;
      if (yVar % N == y || (yVar % N == 0 && y == N))
        return xVar; // EXIT(func) : 1. case

      if (xVar > lcm)
        return -1; // EXIT(func) : 2. case
    }
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
    a.input();
    cout << a.yearCalculator() << "\n";
  }
}