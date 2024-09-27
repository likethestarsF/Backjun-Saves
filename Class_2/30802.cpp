// 240927 2 #30802
// Class 2
// 00:10
#include <algorithm>
#include <iostream>
#include <vector>
// #define MAX 2147483647
// #define ll long long
using namespace std;

class MY {
  int manNum;
  vector<int> tShirts;
  int tBundle, penBundle;

public:
  MY() {
    /* Input */
    cin >> manNum; // [,1e9]
    tShirts.resize(6);
    for (int i = 0; i < 6; i++)
      cin >> tShirts[i];
    cin >> tBundle >> penBundle;
  }

  void body() {

    // tShirts
    int tOrder = 0;
    for (int i = 0; i < 6; i++) {
      tOrder += tShirts[i] / tBundle;
      if (tShirts[i] % tBundle != 0)
        tOrder++;
    }

    // Pen: 30 > 8 * x
    const int maxPenBundle = (manNum / penBundle);
    const int penNum = manNum - maxPenBundle * penBundle;

    cout << tOrder << '\n';
    cout << maxPenBundle << ' ' << penNum;
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  MY my;
  my.body();
}
