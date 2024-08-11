// 240811 3 #2096
// Class 4
// 00:
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class my {
  int N;
  vector<vector<int>> line;

  int FindMax() {
    vector<vector<int>> DP;
    DP.resize(1, vector<int>(2, 0));

    DP[0][0] = max(line[0][0], line[0][1]); // left
    DP[0][1] = max(line[0][2], line[0][1]); // right

    for (int i = 1; i < N; i++) {
      int left = DP[0][0] + line[i][0];
      int mid = max(DP[0][0], DP[0][1]) + line[i][1];
      int right = DP[0][1] + line[i][2];

      DP[0][0] = max(left, mid);
      DP[0][1] = max(right, mid);
    }

    return max(DP[0][0], DP[0][1]);
  }

  int FindMin() {
    vector<vector<int>> DP;
    DP.resize(1, vector<int>(2, 0));

    DP[0][0] = min(line[0][0], line[0][1]); // left
    DP[0][1] = min(line[0][2], line[0][1]); // right

    for (int i = 1; i < N; i++) {
      int left = DP[0][0] + line[i][0];
      int mid = min(DP[0][0], DP[0][1]) + line[i][1];
      int right = DP[0][1] + line[i][2];

      DP[0][0] = min(left, mid);
      DP[0][1] = min(right, mid);
    }

    return min(DP[0][0], DP[0][1]);
  }

public:
  void body() {
    cin >> N; // [1, 100,000]
    line.resize(N, vector<int>(3));
    for (int i = 0; i < N; i++)
      cin >> line[i][0] >> line[i][1] >> line[i][2]; // [0,9]

    cout << FindMax() << ' ' << FindMin();
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