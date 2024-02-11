// 240127 9 #10250
#include <array>
#include <iostream>
#include <string>
using namespace std;

void body() {
  // input
  int t;
  cin >> t;

  int *h = new int[t];
  int *w = new int[t];
  int *n = new int[t];

  for (int i = 0; i < t; i++) {
    cin >> h[i] >> w[i] >> n[i];
  }

  // process
  int *flo = new int[t];
  int *roo = new int[t];

  for (int i = 0; i < t; i++) {
    int div = n[i] / h[i];
    int mod = n[i] % h[i];
    flo[i] = mod;
    roo[i] = div + 1;
    if (mod == 0) {
      flo[i] = h[i];
      roo[i]--;
    }
  }

  // output
  for (int i = 0; i < t; i++) {
    if (roo[i] > 9)
      cout << flo[i] << roo[i] << '\n';
    else
      cout << flo[i] << 0 << roo[i] << '\n';
  }
}

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  // cin.tie(NULL);
  // cout.tie(NULL);

  /* clog switch */
  std::clog.setstate(std::ios_base::failbit);

  body();
}