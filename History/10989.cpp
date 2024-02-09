// 240209 3 #10989
/* Using STL sort is the easiest way.
** However, because of the memory restriction we cannot apply STL sort.
** Use Counting Sort.
** the problem's condition is very unique.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void body() {
  // input
  int maxNum = 10000;
  int n;
  cin >> n;

  vector<int> list(maxNum, 0);
  for (int i = 0; i < n; i++) {
    int inputInt;
    cin >> inputInt;
    list[inputInt - 1]++;
  }

  // output
  for (int i = 0; i < maxNum; i++) {
    while (list[i] > 0) {
      cout << i + 1 << '\n';
      list[i]--;
    }
  }
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