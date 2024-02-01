// 240201 4 #10866
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class deque {
  vector<int> body;
  bool is_empty() { return (body.begin() == body.end()); }

public:
  // constructor
  deque(){};

  void push_front(int n) { body.insert(body.begin(), n); }
  void push_back(int n) { body.push_back(n); }
  int pop_front() {
    if (is_empty()) {
      return -1;
    } else {
      int temp = body.front();
      body.erase(body.begin());
      return temp;
    }
  }
  int pop_back() {
    if (is_empty()) {
      return -1;
    } else {
      int temp = body.back();
      body.pop_back();
      return temp;
    }
  }
  int size() { return body.size(); }
  bool empty() { return is_empty(); }
  int front() { return is_empty() ? -1 : body.front(); }
  int back() { return is_empty() ? -1 : body.back(); }
};

void body() {
  deque d;

  // input
  int n;
  cin >> n;
  while (n--) {
    string cmd;
    cin >> cmd;
    if (cmd == "push_front") {
      int elem;
      cin >> elem;
      d.push_front(elem);
    } else if (cmd == "push_back") {
      int elem;
      cin >> elem;
      d.push_back(elem);
    } else if (cmd == "pop_front") {
      cout << d.pop_front() << '\n';
    } else if (cmd == "pop_back") {
      cout << d.pop_back() << '\n';
    } else if (cmd == "size") {
      cout << d.size() << '\n';
    } else if (cmd == "empty") {
      cout << d.empty() << '\n';
    } else if (cmd == "front") {
      cout << d.front() << '\n';
    } else if (cmd == "back") {
      cout << d.back() << '\n';
    } else {
      cerr << " input error\n";
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