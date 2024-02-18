// 240218 7 #1107
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {
  vector<int> target;
  int targetInt;
  int numBroken;
  vector<bool> button;

public:
  void in() {
    string str;
    cin >> str;
    targetInt = stoi(str);

    target.resize(str.size());
    for (int i = 0; i < str.size(); i++) {
      target[i] = (int)(str[i] - 48);
    } // [0] is the biggest digit

    button.resize(11, true);

    cin >> numBroken;
    for (int i = 0; i < numBroken; i++) {
      int input;
      cin >> input;
      button[input] = false;
    }
  }

  void body() {
    // compare two value

    // 1. move from ch. 100 (only use +, -)

    // 2. move from most closest ch. X
    // how to find ch.X ?
    // 1.
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
  a.in();
}