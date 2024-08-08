// 240808 2 #12005
// Random Marathon 10 F
// 00:15
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {
  int diaNum, sizeDiff;
  vector<int> dia;

public:
  void body() {
    cin >> diaNum >> sizeDiff; // [, 1000] , [0, 10000]
    dia.resize(diaNum);
    for (int i = 0; i < diaNum; i++)
      cin >> dia[i];
    sort(dia.begin(), dia.end());

    int max = 1;
    // Consider cur is the min_size of dia
    for (int cur = 0; cur < diaNum; cur++) {
      int cnt = 0;
      for (int i = cur; i < diaNum; i++) {
        if (abs(dia[cur] - dia[i]) <= sizeDiff)
          cnt++;
        else
          break;
      }

      max = std::max(max, cnt);
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