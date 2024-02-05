// 240205 1 #15829
#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

void body() {
  // definiton
  int r = 31, m = 1234567891;

  // input
  int l;
  cin >> l;
  string str;
  cin >> str;

  //  process
  vector<int> aHash;
  for (const char &c : str) {
    aHash.push_back((int)(c - 96)); // 'a' is 97.
  }

  // sigma
  unsigned long long h = 0;
  unsigned long long square = 1;
  for (int i = 0; i < l; i++) {
    unsigned long long tempSum = aHash[i] * square % m;
    h += tempSum;
    h %= m;

    square *= r;
    square %= m;
  }

  // output
  cout << h;
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