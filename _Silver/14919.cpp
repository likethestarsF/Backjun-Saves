// 240807 1 #14919
// Random Marathon 10 H
// 00:
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {
  int m, numbersSize;
  vector<float> numbers = {};
  vector<int> numbersCnt;

public:
  void body() {
    // Input
    cin >> m; // [1, 1000]

    while (!cin.eof()) {
      float number;
      cin >> number; // [0, 1)

      // if (number < 0)
      // goto EXIT;
      numbers.push_back((number + 0.0000001));
    }
    // EXIT:

    numbersSize = numbers.size(); // [1, 1000000]
    sort(numbers.begin(), numbers.end());

    numbersCnt.resize(m, 0);

    // Process
    float bd_low = 0;
    float bd_basic = ((float)1 / m);
    float bd_high = bd_basic;

    int idxForCnt = 0;
    for (int i = 0; i < numbersSize; i++) {
      clog << "current : " << numbers[i] << ' ' << bd_low << "bd low and high"
           << bd_high << endl;

      if (numbers[i] >= bd_low && numbers[i] < bd_high) {
        clog << "added at " << idxForCnt << endl;
        numbersCnt[idxForCnt]++;
      }

      else {
        // update the boundaries
        idxForCnt++;
        bd_low = bd_high;
        bd_high = (1 + idxForCnt) * bd_basic;

        // re-check the ith elem again.
        i--;

        if (idxForCnt == m)
          break;
      }
    }

    // Output
    // clog << bd_basic << endl;
    for (int i = 0; i < m; i++)
      cout << numbersCnt[i] << ' ';
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  std::clog.setstate(std::ios_base::failbit);

  my a;
  a.body();
}
