// 240209 3 #10989
/* Using STL sort is the easiest way.
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void body() {
  // input
  int n;
  cin >> n;
  vector<int> list(n);
  for (int i = 0; i < n; i++) {
    cin >> list[i];
  }

  //  process
  sort(list.begin(), list.end());

  // output
  for (const auto &elem : list) {
    cout << elem << '\n';
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