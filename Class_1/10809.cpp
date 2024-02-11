// 240127 10 #10809
#include <iostream>
#include <string>
using namespace std;

void body() {
  // input
  string s;
  cin >> s;

  // process
  int arr[26];
  fill_n(arr, 26, -1);

  // 'a' = 97, 'z' = 122
  int cnt = 0;
  for (const char &c : s) {
    int ascii = (int)c - 97;
    if (arr[ascii] == -1) {
      arr[ascii] = cnt;
    }
    cnt++;
  }

  // output
  for (int i = 0; i < 26; i++) {
    cout << arr[i] << ' ';
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