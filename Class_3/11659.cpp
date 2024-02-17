// 240217 2 #11659
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {
  vector<long> prefixSum;

public:
  void input2nd(int &typesOfN) {
    long prevPush = 0;
    for (int i = 0; i < typesOfN; i++) { // second Line input
      long forPush;
      cin >> forPush;
      forPush += prevPush;
      prefixSum.push_back(forPush);
      prevPush = forPush; // udapte prev input
    }
  }
  void inputRange(int &sumTimes) {
    for (int i = 0; i < sumTimes; i++) {
      int start, end;
      cin >> start >> end;

      cout << calcSum(start - 1, end - 1) << '\n'; // output
    }
  }

  long calcSum(const int &start, const int &end) {
    if (start == 0)
      return prefixSum[end];
    else {
      return (prefixSum[end] - prefixSum[start - 1]);
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
  int n, m;
  cin >> n >> m;

  a.input2nd(n);
  a.inputRange(m);
}