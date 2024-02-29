// 240227 2 #5430
// 240229 1 #5430
#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
using namespace std;

class my {
  string command;
  int numOfArr;
  string arr;
  bool isReversed = false;
  bool isError = false;

public:
  void body() {
    deque<int> nList = {};
    input(nList);
    exeCommand(nList);
    output(nList);
  }
  template <typename T> void input(T &nList) {
    // init constants.
    isReversed = false;
    isError = false;

    cin >> command;
    cin >> numOfArr;
    cin >> arr;

    // transfer string arr to deque<int>
    string cache = {};
    for (const auto c : arr) {
      if (c != ',' && c != '[' && c != ']') {
        cache += c;
      } else {
        if (!cache.empty())
          nList.push_back(stoi(cache));
        // clog << cache << endl;
        cache = {};
      }
    }
  }

  template <typename T> void exeCommand(T &nList) {
    for (const auto c : command) {
      if (c == 'R') {
        isReversed = !isReversed;
      } else if (c == 'D') { // 'D': pop the first elem
        if (nList.empty()) {
          isError = true;
          break; // EXIT: for loop
        }
        if (isReversed) {
          nList.pop_back();
        } else {
          nList.pop_front();
        }
      } else
        continue;
    }
  }

  template <typename T> void output(T &nList) {
    if (isError) {
      cout << "error" << '\n';
      return; // EXIT: output function
    }
    cout << '[';

    if (nList.size() == 0) {
    }

    else if (isReversed) {
      for (int i = nList.size() - 1; i > 0; i--) {
        cout << nList[i];
        cout << ',';
      }
      cout << nList.front();
    }

    else {
      for (int i = 0; i < nList.size() - 1; i++) {
        cout << nList[i];
        cout << ',';
      }
      cout << nList.back();
    }

    cout << "]\n";
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
  int t;
  cin >> t;
  while (t--) {
    a.body();
  }
}