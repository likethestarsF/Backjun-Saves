// 240229 2 #5525
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {
  int nForP;
  int length;
  char c;
  vector<int> list = {};

public:
  void input() {
    cin >> nForP;
    cin >> length;
  }

  void inputChar() {
    bool IsStarted = false;
    char cPrev = ' ';
    int cntIO = 0;

    for (int i = 0; i < length; i++) {
      cin >> c; // input by char

      // 2. When started, Check (I-O & O-I) or (I-I & O-O)
      // by comparing c and cPrev
      if (IsStarted) {
        if (cPrev == c) {
          IsStarted = false;
          list.push_back(cntIO / 2); // IOIO -> 3/2 = 1, IOIOI -> 4/2 = 2
        } else {
          cntIO++;
        }
      }

      // 1. start to count IOIO... by cntIO
      if (!IsStarted && c == 'I') {
        cntIO = 0;
        IsStarted = true;
      }

      cPrev = c; // update cPrev
    }

    list.push_back(cntIO / 2);
  }

  int calculate() {
    int cnt = 0;
    for (const auto elem : list) {
      if (elem >= nForP)
        cnt += (elem - nForP + 1);
    }
    return cnt;
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
  a.input();
  a.inputChar();
  cout << a.calculate();
}