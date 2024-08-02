// 240802 2 #6504
// Random Marthon 9 E
// 00:40
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {
  int testNum;
  vector<int> fibo = {};

  void makeFibonacci() {
    fibo.push_back(1);
    fibo.push_back(2);

    while (true) {
      if (fibo[fibo.size() - 1] + fibo[fibo.size() - 2] < 25000)
        fibo.push_back(fibo[fibo.size() - 1] + fibo[fibo.size() - 2]);
      else
        break; // size = 21, fibo[20] = 17711
    }
  }

  int convertToMile(const vector<bool> &convertedN) {
    int result = 0, i_fibo = 0;
    for (int i = convertedN.size() - 1; i >= 0; i--) {
      if (convertedN[i] == true)
        result += fibo[i_fibo];
      i_fibo++;
    }
    return result;
  }

public:
  void body() {
    makeFibonacci();
    cin >> testNum; // (0, 25000)

    while (testNum--) {
      // input
      int targetN;
      cin >> targetN; // (2, 25000)

      // Convert N to fibo-form
      vector<bool> convertedN = {};
      int flagUpdated = -1; // -1: initial, 0: non-updated, 1:updated

      for (int i = fibo.size() - 1; i >= 0; i--) {

        if (flagUpdated != 1 && targetN - fibo[i] >= 0) {
          convertedN.push_back(true);
          targetN -= fibo[i];
          flagUpdated = 1;
          continue;
        }

        if (flagUpdated != -1) {
          flagUpdated = 0;
          convertedN.push_back(false);
        }
      }

      // shift the converted form
      convertedN.pop_back();

      // output
      cout << convertToMile(convertedN) << '\n';
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
  a.body();
}