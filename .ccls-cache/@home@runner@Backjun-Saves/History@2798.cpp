// 240128
// 1
// #2798
#include <iostream>
#include <string>
using namespace std;

void body() {
  // input
  int n, m;
  cin >> n >> m;
  int *a = new int[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  // process
  int sum = 0;

  // choose 3 cards : Brute Force [i, j, k]
  for (int i = 0; i < n; i++) {
    int cache;
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        cache = a[i] + a[j] + a[k];
        if (cache > m) {
          continue;
        } else {
          sum = max(sum, cache);
        }
      }
    }
  }

  // output
  cout << sum;
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