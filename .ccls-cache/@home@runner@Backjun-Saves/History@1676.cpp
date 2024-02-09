// 240209 2 #1676
/* count how many factor 10 exists.
** just count the number of 2 and 5 each.
**and find the minimum of count of those.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int countFactor(int target, int divisor) {
  int sum = 0;
  while (target % divisor == 0) {
    sum++;
    target /= divisor;
  }
  return sum;
}

void body() {
  // input
  int n;
  cin >> n;

  int numOf2 = 0;
  int numOf5 = 0;
  for (int i = 1; i <= n; i++) {
    // count numOf2
    numOf2 += countFactor(i, 2);
    // count numOf5
    numOf5 += countFactor(i, 5);
  }

  // output
  int numOf10 = min(numOf2, numOf5);
  cout << numOf10;
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