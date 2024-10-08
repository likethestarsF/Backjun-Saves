// 241009 1 #1918
// Class 4
// 00:
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
// #define INF 1e8
// #define MAX 2147483647
// #define ll long long
using namespace std;

class MY {

public:
  MY() {}

  void body() {
    /* Input */
    string origin;
    cin >> origin; // [,100] : +-*/, (), A~Z

    /**
     * 1. Process the input :
     * 1-1. if Input is latin, go through
     * 1-2. if '(', push it to the stack
     * 1-3. if ')', pop the stack until '(' is found
     * 1-4. if operators, push it to the stack based on the order
     */

    stack<char> s = {};
    for (int i = 0; i < origin.size(); i++) {
      const char *input = &origin[i];

      if (*input == '(')
        s.push(*input);

      else if (*input == ')') {
        while (!s.empty()) {
          const char cur = s.top();
          s.pop();

          if (cur == '(')
            break;

          cout << cur;
        }
      }

      else if (*input == '*' || *input == '/')
        s.push(*input);

      else if (*input == '+' || *input == '-') {
        while (!s.empty()) {
          const char cur = s.top();

          if (cur == '(')
            break;

          cout << cur;
          s.pop();
        }

        s.push(*input);
      }

      else // 1-1. latin
        cout << *input;
    }

    while (!s.empty()) {
      const char cur = s.top();
      s.pop();

      cout << cur;
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

  MY my;
  my.body();
}
