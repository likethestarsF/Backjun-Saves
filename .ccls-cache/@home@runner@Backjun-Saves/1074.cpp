// 240213 2 #1074
// 240214 1 #1074
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int exp(const int &n) {
  int result = 1;
  for (int i = 0; i < n; i++)
    result *= 2;
  return result;
}

int rangeOfN(int n) {
  if (n == 0)
    return 0;
  else {
    int rBound = 1;
    int cnt = 0;
    while (n >= rBound) {
      cnt++;
      rBound *= 2;
    }
    return cnt;
  }
}

class z {
  int n;    // 2^n * 2^n : n<=15
  int r, c; // r: row c: column

public:
  int totCnt = 0;
  z() {
    cin >> n;
    cin >> r >> c;
  }
  void divide() {
    // input is n
    if (n == 1) {
      if (r == 1)
        totCnt += 2;
      if (c == 1)
        totCnt++;
    } else {
      int stdLine = exp(n - 1);
      const int box = stdLine * stdLine;
      if (r < stdLine) {
        if (c < stdLine) { // 1
          // nothing to do. just shrink.
        } else { // 2: contains line
          // add 1 box
          totCnt += box;
          c -= stdLine;
        }
      } else {
        if (c < stdLine) { // 3
          // add 2 box
          totCnt += box * 2;
          r -= stdLine;
        } else { // 4: contains line
          // add 3 box
          totCnt += box * 3;
          r -= stdLine;
          c -= stdLine;
        }
      }
      n--;
      divide();
    }
  }
};

void body() {
  z callZ;
  callZ.divide();
  cout << callZ.totCnt;
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