// 240816 1 #30328
// Random Marathon 11 A
// 00:00
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {

public:
  void body() {
    int n;
    cin >> n;
    cout << n * 4000;
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