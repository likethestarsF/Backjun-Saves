// 240211 2 #11723
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {
  const vector<bool> sAll = vector<bool>(20, 1);
  const vector<bool> sNone = vector<bool>(20, 0);
  vector<bool> s = vector<bool>(20, 0);

  template <class T> void log_test(T print);

public:
  void add(const int &n) { s[n - 1] = 1; }
  void remove(const int &n) { s[n - 1] = 0; }

  void check(const int &n) { cout << s[n - 1] << '\n'; }
  void toggle(const int &n) { s[n - 1] = !s[n - 1]; }
  void all() { s = sAll; }
  void empty() { s = sNone; }
};

template <class T> void my::log_test(T print) {
  for (const auto &elem : print)
    clog << "\nLOG TEST : " << elem << endl;
}

void body() {
  // input
  int t;
  cin >> t;

  my m;
  while (t--) {
    string inputStr;
    cin >> inputStr;

    int inputInt = -1;
    if (inputStr == "add") {
      cin >> inputInt;
      m.add(inputInt);
    } else if (inputStr == "remove") {
      cin >> inputInt;
      m.remove(inputInt);
    } else if (inputStr == "check") {
      cin >> inputInt;
      m.check(inputInt);
    } else if (inputStr == "toggle") {
      cin >> inputInt;
      m.toggle(inputInt);
    } else if (inputStr == "all") {
      m.all();
    } else if (inputStr == "empty") {
      m.empty();
    } else
      cerr << "invaild input\n";
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