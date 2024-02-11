// 240127 5 #2884
#include <iostream>
#include <string>
using namespace std;

void body() {
  int H, M;
  int M_temp;
  int H_res, M_res;
  cin >> H >> M;

  M_temp = M - 45;
  // negative -> H-1 / chagne M
  if (M_temp < 0) {
    M_res = M_temp + 60; // -15 -> 45
    H_res = H - 1;
  } else {
    M_res = M_temp;
    H_res = H;
  }

  if (H_res < 0) {
    H_res = 23;
  }

  cout << H_res << ' ' << M_res;
}

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  // cout.tie(NULL);

  /* clog switch */
  std::clog.setstate(std::ios_base::failbit);

  body();
}