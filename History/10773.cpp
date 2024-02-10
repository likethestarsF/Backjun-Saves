// 240210 4 #10773
/* Sum is smaller than 2^32 - 1 : use int type.
** Use vector to save the input.
** pop_back if input is 0.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void body() {
  // input
  int k;
  cin >> k;

  //  process
  vector<int> v;
  while (k--) {
    int temp;
    cin >> temp;
    if (temp == 0)
      v.pop_back();
    else
      v.push_back(temp);
  }
  int sum = 0;
  for (const auto &elem : v)
    sum += elem;

  // output
  cout << sum;
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