// 240205 2 #2869
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void body() {
  // input
  int a, b, v;
  cin >> a >> b >> v;

  //  process
  int snailPosition = 0;
  int day = 0;
  for (int i = 1;; i++) {
    // climb a meter at day.
    snailPosition += a;
    // fall b meter at night.
    if (snailPosition >= v) {
      day = i;
      break;
    }
    snailPosition -= b;
  }

  // output
  cout << day;
}

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  body();
}