// 240306 3 #11727
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class tile {
  vector<int> table;

public:
  int n;

  /* (n + 1)th cases are same to (n-1)th cases times 3
  ** An = Bn-1 + Cn-2;
  ** An = A(n-1) + 2*A(n-2);
  */

  void initTable() {
    table.resize(n + 1); // in order to use table[n]. n >= 1
    table[0] = 1;        // 0 is fit in the reality but assign 1 for n==2 case
    table[1] = 1;        // only 2x1 case is possible
  }

  void DP() {
    initTable();
    // the relation cannot be applied if n is 1
    if (n < 2) {
      cout << table[n];
      return;
    }

    for (int i = 2; i <= n; i++) {
      table[i] = table[i - 1] + 2 * table[i - 2];
      table[i] %= 10007;
    }

    cout << table[n];
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  tile a;
  cin >> a.n;
  a.DP();
}