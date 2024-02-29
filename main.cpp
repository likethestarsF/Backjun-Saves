// 240229 3 #6064
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {
  // 1. If <M:N> represents the lastest year of Inka calendar,
  // find XX : <x:y> is the XXth year.
  // 2. If <x:y> is invalid expression, return -1.
  // M, N | [1.40000]
  int M, N, x, y;

public:
  void input() { cin >> M >> N >> x >> y; }

  int yearCalculator() {
    int xVar = 1, yVar = 1;
    int yearCnt = 1;

    while (true) {
      if (xVar == x && yVar == y)
        return yearCnt; // EXIT(func) : answer

      if (xVar == M && yVar == N)
        return -1; // EXIT(func) : when the lastest year reached - 2. case

      if (xVar == M)
        xVar = 1;
      else
        xVar++;

      if (yVar == N)
        yVar = 1;
      else
        yVar++;

      yearCnt++;
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