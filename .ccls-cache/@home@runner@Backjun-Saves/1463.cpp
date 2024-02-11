// 240211 8 #1463
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class dp {
  vector<int> dpTable; // store actionCnt
  void divByX(const int input, const int x);

public:
  void output() { cout << dpTable[1]; }
  int n;

  dp() {
    // input
    cin >> n;
    dpTable = vector<int>(n + 1, 0);
  }

  void test() {
    for (int i = 1; i < dpTable.size(); i++)
      cout << i << "st number : " << dpTable[i] << endl;
  }

  /*
  ** Call 3 method. store the result in dpTable.
  ** 1. divByX(3)
  ** 2. divByX(2)
  ** 3. decrease()
  */
  void process(const int k) {
    if (k > 1) {
      /* divBy3 */
      divByX(k, 3);
      /* divBy2 */
      divByX(k, 2);
      /* decrease by 1 */
      int index = k - 1;
      if (dpTable[index] == 0) {
        dpTable[index] = dpTable[k] + 1;
        process(index); // recursion
      } else if (dpTable[index] >= (dpTable[k] + 1)) {
        dpTable[index] = dpTable[k] + 1;
        process(index); // recursion
      }
    }
  }
};

void body() {
  dp number;
  number.process(number.n);
  // number.test();
  number.output();
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

void dp::divByX(const int input, const int x) {
  if (input % x == 0) {
    int index = input / x;

    if (dpTable[index] == 0) {
      dpTable[index] = dpTable[input] + 1;
      process(index); // recursion
    } else if (dpTable[index] >= (dpTable[input] + 1)) {
      dpTable[index] = dpTable[input] + 1;
      process(index); // recursion
    }
  }
}