// 240809 1 #24927
// Random Marathon 10 D
// 00:15
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {
  int numSize, K;

public:
  void body() {
    cin >> numSize >> K; // [1, 100000] [0 , 1000]
    for (int i = 0; i < numSize; i++) {
      int x;
      cin >> x; // [1, 10^9]

      while (x % 2 == 0) {
        x /= 2;
        K--;
      }
    }

    if (K > 0)
      cout << 0 << '\n';
    else
      cout << 1 << '\n';
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