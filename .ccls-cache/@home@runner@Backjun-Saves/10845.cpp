// 240201 3 #10845
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class queue {
  vector<int> body;
  int i = 0;
  vector<int>::iterator fr;
  bool is_empty() { return (fr == body.end()); }

public:
  queue() { fr = body.begin(); }
  void push(int n) {
    body.push_back(n);
    fr = body.begin() + i;
  }

  int pop() {
    if (is_empty()) {
      return -1;
    } else {
      int temp;
      temp = *(body.begin() + i);
      i++;
      fr = body.begin() + i;
      return temp;
    }
  }
  int size() { return (body.end() - fr); }
  bool empty() { return is_empty(); }
  int front() {
    if (is_empty()) {
      return -1;
    } else {
      return *fr;
    }
  }
  int back() {
    if (is_empty()) {
      return -1;
    } else {
      return *(body.end() - 1);
    }
  }
};

void body() {
  queue q;

  // input
  int n;
  cin >> n;
  while (n--) {
    string cmd;
    cin >> cmd;
    if (cmd == "push") {
      int elem;
      cin >> elem;
      q.push(elem);
    } else if (cmd == "pop") {
      cout << q.pop() << '\n';
    } else if (cmd == "size") {
      cout << q.size() << '\n';
    } else if (cmd == "empty") {
      cout << q.empty() << '\n';
    } else if (cmd == "front") {
      cout << q.front() << '\n';
    } else if (cmd == "back") {
      cout << q.back() << '\n';
    } else
      cerr << " command input error\n";
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