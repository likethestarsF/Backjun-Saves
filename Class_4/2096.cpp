// 240811 3 #2096
// Class 4
// 00:50
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class my {
  vector<int> minDP, maxDP;

public:
  void body() {
    int N;
    cin >> N; // [1, 100,000]

    // init. DPs
    minDP.resize(2, 0);
    maxDP.resize(2, 0); // <= 100000 * 9
    {
      int l, m, r;
      cin >> l >> m >> r;
      maxDP[0] = max(l, m);
      maxDP[1] = max(r, m);
      minDP[0] = min(l, m);
      minDP[1] = min(r, m);
    }

    for (int i = 1; i < N; i++) {
      int l, m, r;
      cin >> l >> m >> r; // [0,9]

      // Min
      {
        int left = minDP[0] + l;
        int mid = min(minDP[0], minDP[1]) + m;
        int right = minDP[1] + r;
        minDP[0] = min(left, mid);
        minDP[1] = min(right, mid);
      }

      // Max
      {
        int left = maxDP[0] + l;
        int mid = max(maxDP[0], maxDP[1]) + m;
        int right = maxDP[1] + r;
        maxDP[0] = max(left, mid);
        maxDP[1] = max(right, mid);
      }
    }

    cout << max(maxDP[0], maxDP[1]) << ' ' << min(minDP[0], minDP[1]);
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