// 240907 2 #2166
// Class 5
// 00:15
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

class my {
  struct coord {
    int x, y;
  };
  int N;

public:
  void body() { /* INPUT */
    cin >> N;   // [3, 10000]
    vector<coord> point(N);
    for (int i = 0; i < N; i++) {
      cin >> point[i].x;
      cin >> point[i].y;
    }

    /**
     * Shoelace Formula
     * Find area of polygons
     * A = 0.5 * sigma(x_i(y_i+1 - y_i-1)) > 0
     */

    ll int area = 0;
    for (int i = 0; i < N; i++) {
      int curX = point[i].x;
      int curY1, curY2;
      if (i + 1 < N)
        curY1 = point[i + 1].y;
      else
        curY1 = point[0].y;

      if (i - 1 < 0)
        curY2 = point[N - 1].y;
      else
        curY2 = point[i - 1].y;

      area += curX * (curY1 - curY2);
    }

    if (area < 0)
      area *= -1;

    cout << (ll int)(area / 2);
    if (area % 2 == 0)
      cout << ".0\n";
    else
      cout << ".5\n";
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
