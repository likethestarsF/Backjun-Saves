// 240817 1 #16461
// Random Marathon 11 H
// 00:30
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {
  int testN;

  int MinButton(const int &freq, const int &tar) {
    int MIN = 6; // manual input by numpad
    // 1. target = cur
    if (freq == tar)
      return 0;

    // 2. basic up down case
    int delta = abs(freq - tar);
    if (delta < 120 && delta % 20 == 0)
      MIN = min(MIN, delta / 20);

    // 3. out of boundary by updown
    if (tar % 20 == 0) {
      int tar_delta = (tar - 144000) / 20; // 144100 or 145900
      // only up button
      if (tar_delta < 6) {
        int cnt = 0, cur = freq;
        while (true) {
          cnt++;
          cur += 20;
          if (cur > 146000)
            break;
        }
        MIN = min(MIN, cnt + tar_delta);
      }

      // only down button
      else if (tar_delta > 94) {
        int cnt = 0, cur = freq;
        while (true) {
          cnt++;
          cur -= 20;
          if (cur < 144000)
            break;
        }
        MIN = min(MIN, cnt + 100 - tar_delta);
      }
    }

    return MIN;
  }

public:
  void body() {
    cin >> testN; // 5000
    while (testN--) {
      float freqA, freqB, freqTarget;
      char freqCur;
      cin >> freqA >> freqB >> freqCur >> freqTarget; // [144.000, 146.000]

      if (freqCur == 'A')
        cout << min(MinButton(freqA * 1000, freqTarget * 1000),
                    1 + MinButton(freqB * 1000, freqTarget * 1000))
             << '\n';
      else
        cout << min(1 + MinButton(freqA * 1000, freqTarget * 1000),
                    MinButton(freqB * 1000, freqTarget * 1000))
             << '\n';
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