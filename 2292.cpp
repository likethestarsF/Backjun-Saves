// 240204 1 #2292
/* Beehive
** start: room 0 not 1
** 0  ~  0 : 1 : 1
** 1  ~  6 : 6 * (1) : 2
** 7  ~ 18 : 6 * (1 + 2) : 3 -> 7~17 / 6 = 1~2
** 19 ~ 36 : 6 * (1 + 2 + 3) : 4 -> 19~35 / 6 = 3~4
** 37 ~ 60 : 6 * (1 + 2 + 3 + 4) : 5
** ...
** XX ~ XX : 6 * ( N*(N + 1)/2 ) : (N + 1)
** N+1 is minimum of room number.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void body() {
  // input
  int n;
  cin >> n;

  //  process
  float nModified = (n - 1) / 6; // 15 -> 2
  int roomNum = 0;
  for (int i = 1;; i++) {
    if (nModified < i * (i + 1) / 2) {
      roomNum = i + 1;
      break;
    }
  }

  // avoid +1 for 1, 6, 18, ... and so on.
  if (n - 1 == 6 * (roomNum - 2) * (roomNum - 1) / 2 || n == 1)
    roomNum--;
  // output
  cout << roomNum;
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