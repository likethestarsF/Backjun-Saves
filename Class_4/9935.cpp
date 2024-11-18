// 241118 1 #9935
// Class 4
// 02:00
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
// #define INF 1e8
// #define MAX 2147483647
// #define ll long long
using namespace std;

class MY {
  string input, explosive;

public:
  MY() {
    /* Input */
    cin >> input;     // [,1e6]
    cin >> explosive; // [,36]
  }

  void body() {
    stack<char> s = {};
    // push unless we find explosive.back()
    for (int i = 0; i < input.length(); i++) {
      s.push(input[i]);

      if (input[i] == explosive.back() && s.size() >= explosive.length()) {
        string sample;
        sample.resize(explosive.length());
        for (int i = explosive.length() - 1; i >= 0; i--) {
          sample[i] = s.top();
          s.pop();
        }

        if (sample != explosive) {
          for (int i = 0; i < sample.length(); i++)
            s.push(sample[i]);
        }
      }
    }

    /* Output */
    if (s.empty())
      cout << "FRULA";

    else {
      vector<char> result = {};
      while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
      }

      for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i];
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
