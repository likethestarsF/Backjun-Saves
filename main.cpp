// 240209 3 #10989
/* Using STL sort is the easiest way.
** However, because of the memory restriction we cannot apply STL sort.
** we should input the data and do sorting simultaneously.
** Linear Search causes Timeout.
** Binary Search will be helpful.
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void body() {
  vector<int> list;

  // input
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int inputInt;
    cin >> inputInt;

    // sorting process.
    auto itr = lower_bound(list.begin(), list.end(), inputInt);

    if (itr == list.end())
      list.push_back(inputInt);
    else
      list.insert(itr, inputInt);
  }

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