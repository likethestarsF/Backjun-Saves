// 240211 8 #1463
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void body() {
  // input
  int n;
  cin >> n;

  // Three action
  int actionCnt = 0;
  while (n > 1) {
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 3 == 1) {
      n--;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n--;
    }
    actionCnt++;
  }

  // output
  cout << actionCnt;
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