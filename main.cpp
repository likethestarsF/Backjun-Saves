// 240213 2 #1074
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
  int n;              // 2^n * 2^n : n<=15
  int r, c;           // r: row c: column
  int rRange, cRange; // n : 00 <= <2^n
  int totCnt = 0;

public:
  z() {
    cin >> n;
    cin >> r >> c;

    // Find the location of r and c.
    // exception: 0 ; generally [2^(n-1), 2^n)
    rRange = rangeOfN(r); // right bound;
    cRange = rangeOfN(c);
  }

  void divide() { // what if n is 1?
    /*
    ** Divide step by step. find where is the dot
    ** we are gonna shrink the box.
    ** k:(1~4) shirnk + (k-1) * 2^(line+1)(= n) to totCnt
    */
    int line = n - 1;
    if (rRange < line) {
      if (cRange < line) { // 1
      } else {             // 2
      }
    } else {
      if (cRange < line) { // 3
      } else {             // 4
      }
    }
  }
  void out() { clog << rRange << ":rRange & c Range:" << cRange << endl; }
};

void body() {
  z callZ;
  callZ.out();
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