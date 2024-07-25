// 240725 1 #26027
// Random Marthon 8 B
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {
  int r;

public:
  void body() {
    cin >> r;
    const long long int sq = r * r;

    int xAnswer = -1, yAnswer = -1;

    for (int x = r - 1; x > 0; x--) {
      for (int y = 1; y <= r; y++) {
        long long int tempSq = x * x + y * y;

        // find x^2 + y^2 = r^2 + 1
        if (tempSq == sq + 1) {
          xAnswer = x;
          yAnswer = y;
          goto END;
        }
      }
    }
  END:
    cout << xAnswer << ' ' << yAnswer;
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