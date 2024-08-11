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
    DP.resize(N, vector<int>(3, 0));

    for (int j = 0; j < 3; j++)
      DP[0][j] = line[0][j];

    for (int i = 1; i < N; i++) {
      DP[i][0] = max(DP[i - 1][0], DP[i - 1][1]) + line[i][0];
      DP[i][1] =
          max(max(DP[i - 1][0], DP[i - 1][1]), DP[i - 1][2]) + line[i][1];
      DP[i][2] = max(DP[i - 1][1], DP[i - 1][2]) + line[i][2];
    }

    return max(max(DP[N - 1][0], DP[N - 1][1]), DP[N - 1][2]);
  }

  int FindMin() {
    vector<vector<int>> DP;
    DP.resize(N, vector<int>(3, 0));

    for (int j = 0; j < 3; j++)
      DP[0][j] = line[0][j];

    for (int i = 1; i < N; i++) {
      DP[i][0] = min(DP[i - 1][0], DP[i - 1][1]) + line[i][0];
      DP[i][1] =
          min(min(DP[i - 1][0], DP[i - 1][1]), DP[i - 1][2]) + line[i][1];
      DP[i][2] = min(DP[i - 1][1], DP[i - 1][2]) + line[i][2];
    }

    return min(min(DP[N - 1][0], DP[N - 1][1]), DP[N - 1][2]);
  }

public:
  void body() {
    cin >> N;
    line.resize(N, vector<int>(3));
    for (int i = 0; i < N; i++)
      cin >> line[i][0] >> line[i][1] >> line[i][2];

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