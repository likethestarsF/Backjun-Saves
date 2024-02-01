// 240201 1 #10816
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void body() {
  // condition;
  int card_min = -10000000, card_max = 10000000;

  // input
  int n;
  cin >> n;
  vector<int> ans(card_max - card_min);
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    ans[temp - card_min]++;
  }

  int m;
  cin >> m;
  vector<int> tar(m);
  for (int i = 0; i < m; i++) {
    cin >> tar[i];
  }

  //  process

  // output
  for (int i = 0; i < m; i++) {
    cout << ans[tar[i] - card_min] << " ";
  }
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