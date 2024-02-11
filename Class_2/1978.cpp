// 240127 12 #1978
#include <iostream>
#include <string>
using namespace std;

bool prime(int n) {
  bool tf = true;
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      tf = false;
      break;
    }
  }
  if (n == 1)
    tf = false;
  return tf;
}

void body() {
  // input
  int n;
  cin >> n;
  int *a = new int[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  // process
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (prime(a[i])) {
      cnt++;
    }
  }

  // output
  cout << cnt;
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