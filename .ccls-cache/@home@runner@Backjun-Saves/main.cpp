// 240129 #
#include <iostream>
#include <string>
using namespace std;

void body() {
  // input
  int n;
  cin >> n;
  int *x = new int[n];
  int *y = new int[n];

  for (int i = 0; i < n; i++) {
  }

  // process

  // output

  // Unallocate
  delete[] x;
  delete[] y;
}

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  // cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  body();
}