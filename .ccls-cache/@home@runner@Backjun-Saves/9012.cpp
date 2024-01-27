// 240127
// 12
// #1978
#include <iostream>
#include <string>
using namespace std;

void body() {
  // input
  int n;
  cin >> n;
  string *a = new string[n];
  bool *b = new bool[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  // process
  for (int i = 0; i < n; i++) {
    int val = 0;
    for (const char &c : a[i]) {
      if (c == '(') {
        val++;
      } else if (c == ')') {
        val--;
      }
      if (val < 0) {
        break;
      }
    }
    val == 0 ? b[i] = true : b[i] = false;
  }

  // output
  for (int i = 0; i < n; i++)
    if (b[i])
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
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