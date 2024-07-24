// 240724 1 #17874
// Random Marthon 8 A
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {
  int n, h, v;
  const int thick = 4;

public:
  void body() {
    cin >> n >> h >> v;

    int largeH, largeV;
    largeH = (h > n - h) ? h : n - h;
    largeV = (v > n - v) ? v : n - v;

    cout << thick * largeH * largeV;
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