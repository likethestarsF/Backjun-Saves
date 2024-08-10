// 240810 1 #21734
// Random Marathon 10 B
// 00:
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class my {
  string input;

public:
  void body() {
    cin >> input;

    for (const char &elem : input) {
      int current = elem;
      int sum = 0;

      sum += current / 100;
      current %= 100;
      sum += current / 10;
      current %= 10;
      sum += current;

      for (int i = 0; i < sum; i++)
        cout << elem;
      cout << '\n';
    }
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  my a;
  a.body();
}