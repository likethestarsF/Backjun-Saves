// 240812 2 #31450
// Random Marathon 10 A
// 00:00
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class my {

public:
  void body() {
    int M, K;
    cin >> M >> K;
    if (M % K == 0)
      cout << "Yes";
    else
      cout << "No";
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