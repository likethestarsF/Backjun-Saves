// 240218 9 #1874
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class my {
  stack<int> st = {};
  vector<int> target;
  queue<int> output = {};
  bool possibility = true;

public:
  void in(const int &n) {
    target.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> target[i];
    }
  }

  void body() {
    int index = 0;
    int holding = 1;
    while (index < target.size()) {

      if (holding <= target[index]) {
        // push repeatedly until top is equal to the target
        while (holding <= target[index]) {
          st.push(holding);
          holding++;
          output.push(1);
        }

        // now holding is target + 1
        // the top is target : do pop
        st.pop();
        output.push(0);
        index++;

      } else {
        // Case that already pushed the targeted num.
        if (st.top() == target[index]) {
          st.pop();
          output.push(0);
          index++;
        } else {
          possibility = false;
          break;
        }
      }
    }
  }
  void out() {
    if (possibility) {
      while (!output.empty()) {
        cout << ((output.front()) ? "+" : "-") << "\n";
        output.pop();
      }
    } else {
      cout << "NO";
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
  int n;
  cin >> n;
  a.in(n);
  a.body();
  a.out();
}