// 240204 1 #2231
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int digitGen(int n) {
  int n_max = n;
  int n_min = n_max - 9 * 6; // 999,999
  int result = 0;
  for (int i = n_min; i <= n_max; i++) {
    vector<int> digit;
    int sum = i;

    // digit divide.
    int nDigit = i;
    while (true) {
      if (nDigit < 10) {
        digit.push_back(nDigit);
        break;
      }
      digit.push_back(nDigit % 10);
      nDigit /= 10;
    }

    // digitsum.
    for (const int &elem : digit) {
      sum += elem;
    }
    if (n == sum) {
      result = i;
      break;
    }
  }

  return result;
}

void body() {
  // input
  int n;
  cin >> n;

  // output
  cout << digitGen(n);
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