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
  deque<int> nList;
  string arr;
  bool isReversed = false;
  bool isError = false;

public:
  void input() {
    // init constants.
    nList.clear();
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

  void exeCommand() {
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

  void output() {
    if (isError)
      cout << "error" << '\n';

    else if (isReversed) {
      cout << '[';

      for (int i = nList.size() - 1; i > 0; i--) {
        cout << nList[i];
        cout << ',';
      }
      cout << nList.front();
      cout << "]\n";
    }

    else {
      cout << '[';

      for (int i = 0; i < nList.size() - 1; i++) {
        cout << nList[i];
        cout << ',';
      }
      cout << nList.back();
      cout << "]\n";
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
  int t;
  cin >> t;
  while (t--) {
    a.input();
    a.exeCommand();
    a.output();
  }
}