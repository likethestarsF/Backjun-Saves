// 240810 2 #11660
// Class 4
// 00:30
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct coord {
  int x1, y1, x2, y2;
};

class my {
  int nSize, mSize;
  vector<vector<int>> sq;

public:
  void body() {

    // #input
    cin >> nSize >> mSize; // [1,1024], [1, 100000]

    // [0] for avoiding Segfault.
    sq.resize(nSize + 1, vector<int>(nSize + 1, 0));

    // sum[row][col] += sum[row-1][col] + sum[row][col-1] - sum[row-1][col-1]
    for (int row = 1; row <= nSize; row++)
      for (int col = 1; col <= nSize; col++) {
        cin >> sq[row][col]; // [1,1000]
        sq[row][col] +=
            sq[row - 1][col] + sq[row][col - 1] - sq[row - 1][col - 1];
      }

    // Process
    for (int i = 0; i < mSize; i++) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;

      int result = 0; // 1024 * 1024 * 1000 < 2^30
      result += sq[x2][y2];
      result -= sq[x2][y1 - 1];
      result -= sq[x1 - 1][y2];
      result += sq[x1 - 1][y1 - 1];

      cout << result << '\n';
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
  a.body();
}