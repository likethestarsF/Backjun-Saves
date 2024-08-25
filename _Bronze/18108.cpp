// 240825 1 #18108
// Random Marathon 12 A
// 00:00
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {

public:
  void body() {
    /* INPUT */
    int n;
    cin >> n;
    // transfer 2541 to 1998
    cout << n - 543;
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
