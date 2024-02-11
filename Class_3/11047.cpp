// 240211 5 #11047
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void body() {
  // input
  int n, k;
  cin >> n >> k;

  vector<int> coinList(n);
  while (n--) {
    int temp;
    cin >> temp;
    coinList.at(n) = temp; // biggest goes first.
  }

  /*
  ** We have to make K by coins.
  ** use biggest coin first. and goes down.
  */
  int index = 0;
  int cnt = 0;
  while (k > 0) {
    if (k - coinList[index] >= 0) {
      int numOfCoin = k / coinList[index];
      k -= numOfCoin * coinList[index];
      cnt += numOfCoin;
    }
    index++;
  }

  // output
  cout << cnt;
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