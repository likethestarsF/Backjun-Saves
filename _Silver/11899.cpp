// 240808 1 #11899
// Random Marathon 10 G
// 00:10
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {
  string input;
  int wrongCnt_back = 0;
  int cnt_front = 0;

public:
  void body() {
    cin >> input;

    for (const auto &c : input) {
      if (c == '(') {
        cnt_front++;
      }

      else if (c == ')') {
        if (cnt_front > 0)
          cnt_front--;
        else
          wrongCnt_back++;
      }
    }

    cout << wrongCnt_back + cnt_front;
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