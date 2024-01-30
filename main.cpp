// 240130 1 #1018
#include <iostream>
#include <string>
using namespace std;

int copy8x8(string *str, int m, int n, char C) {
  int cnt = 0; // count error
  for (int i = n; i < n + 8; i++) {
    for (int j = m; j < m + 8; j++) {
      if (str[i][j] != C) {
        cnt++;
      }
      (C == 'B') ? C = 'W' : C = 'B'; // index flip
    }
    (C == 'B') ? C = 'W' : C = 'B'; // index flip
  }
  clog << "cp8x8 m: " << m << " / n : " << n << '\n';
  return cnt;
}

void body() {
  // input
  int n, m;
  cin >> n >> m;

  string *str = new string[m];
  for (auto i = 0; i < n; i++) {
    cin >> str[i];
    clog << "input " << i << str[i] << '\n';
  }

  int min = copy8x8(str, 0, 0, 'B');
  // copy 8*8 board and count wrong color based on init color.
  // and repeat this actions for each 8*8 board.
  // find minimum value;
  // n is vertical, m is horizontal
  for (int i = 0; i <= n - 8; i++) {
    for (int j = 0; j <= m - 8; j++) {
      int temp = copy8x8(str, j, i, 'B');
      if (min > temp)
        min = temp;

      temp = copy8x8(str, j, i, 'W');
      if (min > temp)
        min = temp;
    }
  }

  // output
  cout << min;

  // Unallocate
  delete[] str;
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