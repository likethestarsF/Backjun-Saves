// 240201 2 #10828
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class stack {
  vector<int> body;

public:
  // Constructor
  stack(){};

  void push(int n) { body.push_back(n); }
  int pop() {
    if (body.begin() == body.end()) {
      return -1;
    } else {
      int output = *(body.end() - 1);
      body.pop_back();
      return output;
    }
  }
  int size() { return body.size(); }
  bool empty() { return (body.begin() == body.end() ? true : false); }
  int top() { return (body.begin() == body.end() ? -1 : *(body.end() - 1)); }
};

void body() {

  stack s;
  // input
  int n;
  cin >> n;
  while (n--) {
    string cmd;
    cin >> cmd;
    if (cmd == "push") {
      int elem;
      cin >> elem;
      s.push(elem);
    } else if (cmd == "pop") {
      cout << s.pop() << '\n';
    } else if (cmd == "size") {
      cout << s.size() << '\n';
    } else if (cmd == "empty") {
      cout << s.empty() << '\n';
    } else if (cmd == "top") {
      cout << s.top() << '\n';
    } else {
      cerr << "Error" << '\n';
    }
  }
}

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  body();
}