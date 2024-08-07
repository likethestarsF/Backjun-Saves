// 240807 1 #14919
// Random Marathon 10 H
// 00:
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {
  int m, numbersSize;
  vector<float> numbers;
  vector<int> numbersCnt;

public:
  void body() {
    // Input
    cin >> m;           // [1, 1000]
    cin >> numbersSize; // [1, 1000000]
    numbers.resize(numbersSize);
    numbersCnt.resize(numbersSize, 0);
    for (int i = 0; i < numbersSize; i++)
      cin >> numbers[i];
    sort(numbers.begin(), numbers.end());

    // Process
    float bd_low = 0;
    float bd_basic = 1 / m;
    float bd_high = bd_basic;
    for (int i = 0; i < numbersSize; i++) {
      if (numbers[i] >= bd_low && numbers[i] < bd_high)
        numbersCnt[i]++;
      else {
        // update the boundaries
        bd_low = bd_high;
        bd_high += bd_basic;

        // re-check the ith elem again.
        i--;

        if (bd_low >= 1)
          break; // avoid an infinite loop because of i--;
      }
    }

    // Output
    cout << numbersCnt.size();
    for (const int &elem : numbersCnt)
      cout << elem << ' ';
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
