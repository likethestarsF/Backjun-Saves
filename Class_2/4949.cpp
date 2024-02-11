// 240210 3 #4949
/* Exit COND: input is "."
** COND 2: count the "[" and "]" : those must be continuous.
** COND 3: count the "(" and ")" : ditto.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void body() {
  while (true) {
    // input
    string inputStr;
    getline(cin, inputStr);

    if (inputStr == ".") // Exit COND: while(true)
      break;

    bool flag = true; // flag for yes or no

    // COND 2 & COND 3
    vector<char> recentState = {0}; // 2 elems: '[', '('
    for (const auto &c : inputStr) {
      if (c == '[')
        recentState.push_back('[');

      if (c == '(')
        recentState.push_back('(');

      if (c == ']') {
        if (recentState.back() == '[') {
          recentState.pop_back();
        } else {
          flag = false;
          break;
        }
      }

      if (c == ')') {
        if (recentState.back() == '(') {
          recentState.pop_back();
        } else {
          flag = false;
          break;
        }
      }
    }

    if (recentState.back() != 0)
      flag = false;

    // output
    cout << ((flag) ? "yes" : "no") << '\n';
  }
}

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  std::clog.setstate(std::ios_base::failbit);

  body();
}