// 240308 4 #1107
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define MAX_CHANNEL 500000
using namespace std;

class remoteContoller {
  int target, numBroken;
  vector<bool> button = {};
  const int curChannel = 100;

  bool IsItPossToInput(int n) {
    // 1. boundary check
    if (n < 0)
      return false;

    // 2. button availability check
    string n_str = to_string(n);
    for (auto &digit : n_str) {
      if (!button.at(digit - 48)) {
        return false;
      }
    }

    return true;
  }

  int withoutNumberButton() {
    if (target >= curChannel)
      return (target - curChannel);
    else
      return (curChannel - target);
  }

  // O(N) maybe
  int bruteForce() {
    for (int delta = 0; delta <= MAX_CHANNEL; delta++) {
      // 1. + case
      if (IsItPossToInput(target + delta)) {
        clog << "1. " << target + delta << endl;
        return (to_string(target + delta).length() + delta);
      }

      // 2. - case
      if (IsItPossToInput(target - delta)) {
        clog << "2. " << target - delta << endl;
        return (to_string(target - delta).length() + delta);
      }
    }

    return MAX_CHANNEL;
  }

public:
  remoteContoller(int &n, int &m) {
    target = n;              // n = [0, 500000]
    numBroken = m;           // m = [0, 10]
    button.resize(10, true); // [0,9]

    for (int i = 0; i < m; i++) {
      int temp;
      cin >> temp;
      button[temp] = false;
    }
  }

  void output() {
    int a = withoutNumberButton();
    int b = bruteForce();

    if (a < b)
      cout << a;
    else
      cout << b;
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  std::clog.setstate(std::ios_base::failbit);

  int n, m;
  cin >> n >> m;
  remoteContoller a(n, m);
  a.output();
}