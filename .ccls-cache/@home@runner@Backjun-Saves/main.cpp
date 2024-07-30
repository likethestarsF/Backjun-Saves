// 240731 1 #2992
// Random Marthon 9 H
// 00:
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {

public:
  string X;
  string min = "1000000";

  vector<char> pool = {};

  void updateMax(vector<char> &pool) {
    string target = {};
    for (const auto &i : pool) {
      target += i;
    }

    if (stoi(target) <= stoi(X))
      return;

    min = (stoi(target) > stoi(min)) ? min : target;
  }

  template <typename T> void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
  }

  void body() {
    cin >> X; // [1, 999999], 6! = 720

    for (const char &c : X) {
      pool.push_back(c);
    }
    const vector<char> init = pool;

    // Move the last element to the front side one by one.
    // Repeat 'til order of pool becomes init.

    do {
      string temp = {};
      // move last to front
      for (int i = pool.size() - 1; i > 0; i--) {
        swap(pool[i], pool[i - 1]);

        for (int i = 0; i < pool.size(); i++) {
          vector<char> tempPool = pool;
          swap(tempPool[pool.size() - 1], tempPool[i]);
          updateMax(tempPool);
        }
      }

    } while (init != pool);

    // output
    if (min == "1000000")
      cout << 0;
    else
      cout << stoi(min);
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
  a.body();
}