// 240216 4 #9095
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct tri {
  int d[3];
};

class my {
  vector<int> dptable;

  // factorial using the dp table
  int fact(const int &n) {
    if (dptable[n] == 0)
      dptable[n] = n * fact(n - 1);
    return dptable[n];
  }

  template <typename T> int countCases(const T &cases) {
    int cnt = 0;
    for (const auto &elem : cases) {
      int k = elem.d[0] + elem.d[1] + elem.d[2];
      int cntPartial =
          fact(k) / (fact(elem.d[0]) * fact(elem.d[1]) * fact(elem.d[2]));
      cnt += cntPartial;
    }
    return cnt;
  }

public:
  vector<int> cnt;
  my() {
    dptable = vector<int>(12, 0);
    dptable[0] = 1;
    dptable[1] = 1;
  }

  void IO(int &t) {
    while (t--) {
      int n;
      cin >> n;

      cout << body(n) << '\n'; // returns the answer
    }
  }

  int body(const int &n) {
    // var 1 : number of 3
    int num3 = n / 3;
    // var 2 : number of 2
    int num2 = n / 2;

    vector<tri> cases;
    for (int i = 0; i <= num3; i++)
      for (int j = 0; j <= num2; j++) {
        int remain = n - i * 3 - j * 2; // equal to num1
        // wrong case: jump
        if (remain >= 0) {
          tri forPush = {i, j, remain};
          cases.push_back(forPush);
        }
      }

    return countCases(cases);
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
  a.IO(t);
}