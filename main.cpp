// 240209 3 #10989
/* Using STL sort is the easiest way.
** However, because of the memory restriction we cannot apply STL sort.
** Use Bubble Sort for It uses less memory.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void body() {
  // input
  int n;
  cin >> n;

  vector<short> list(n);
  for (int i = 0; i < n; i++) {
    cin >> list[i];
  }

  // sorting process by Bubble Sort.
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - 1 - i; j++)
      if (list[j] > list[j + 1])
        swap(list[j], list[j + 1]);

  // output
  for (int i = 0; i < n; i++) {
    cout << list[i] << '\n';
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