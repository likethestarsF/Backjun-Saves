// 240802 1 #13238
// Random Marthon 9 F
// 00:20
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct numbers {
  int order;
  int value;
};

bool cmpForNumbers(numbers a, numbers b) {
  if (a.value < b.value)
    return true;
  else if (a.value == b.value)
    return a.order < b.order;
  else
    return false;
}

class my {
  int nMax;
  vector<numbers> bitcoin;

public:
  void body() {
    cin >> nMax; // [1, 10000]
    bitcoin.resize(nMax);
    for (int i = 0; i < nMax; i++) {
      numbers temp;
      cin >> temp.value; // 100000
      temp.order = i;
      bitcoin[i] = temp;
    }
    sort(bitcoin.begin(), bitcoin.end(), cmpForNumbers); // increasing order

    int max = 0;
    for (int i = 0; i < nMax; i++) {
      // select one elem to compare
      numbers current = bitcoin[i];

      // compare with all other elem, by decresing order
      for (int i_reverse = nMax - 1; i_reverse > i; i_reverse--) {
        if (bitcoin[i_reverse].value - current.value < max)
          break; // early break;
        if (bitcoin[i_reverse].order < current.order)
          continue; // pass

        if (bitcoin[i_reverse].value - current.value > max) {
          max = bitcoin[i_reverse].value - current.value;
          break;
        }
      }
    }

    cout << max;
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