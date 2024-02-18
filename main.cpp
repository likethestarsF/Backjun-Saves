// 240217 3 #11726
// 240218 1 #11726
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {
  int caseCnt = 0;

public:
  void recursiveFill(const int &n) {
    if (n == 0 || n == 1) {
      caseCnt %= 10007;
      caseCnt++;
    }

    else {
      recursiveFill(n - 2); // use two 1x2 pieces
      recursiveFill(n - 1); // use a 2x1 piece
    }
  }

  void output() { cout << caseCnt % 10007; }
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
  a.recursiveFill(n);
  a.output();
}