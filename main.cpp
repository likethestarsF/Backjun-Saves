// 240210 2 #2839
/*
** If the number is a multiple of 5: divide by 5. - end of loop
** else if the number is a multiple of: divide by 3. - end of loop
** else minus 5 and go through again above loop.
** when the number is less than 0 : that is the impossible case.
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
  int cnt = 0;
  while (n > 0) {
    if (n % 5 == 0) {
      cnt += n / 5;
      break;
    } else if (n % 3 == 0) {
      cnt += n / 3;
      break;
    } else {
      cnt++;
      n -= 5;
    }
  }
  if (n < 0)
    cnt = -1;

  // output
  cout << cnt;
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