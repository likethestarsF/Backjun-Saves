// 240808 2 #12005
// Random Marathon 10 F
// 00:00
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {
  int diaNum, sizeDiff;
  vector<int> dia;
  vector<int> ifDiff;

public:
  void body() {
    cin >> diaNum >> sizeDiff; // [, 1000] , [0, 10000]
    dia.resize(sizeDiff);
    for (int i = 0; i < diaNum; i++)
      cin >> dia[i];

    ifDiff.resize(1, -1);
    for (int i = 0; i < diaNum; i++) {
      if (i == diaNum - 1) {
        ifDiff.push_back(i);
        break;
      }

      if (abs(dia[i + 1] - dia[i]) > sizeDiff)
        ifDiff.push_back(i);
    }

    int max = 1;
    for (int i = 1; i < ifDiff.size(); i++)
      max = std::max(max, ifDiff[i] - ifDiff[i - 1]);
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