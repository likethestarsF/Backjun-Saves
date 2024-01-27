// 240127 8 #8958
#include <iostream>
#include <string>
using namespace std;

void body() {
  // input
  int t;
  cin >> t;
  string *str = new string[t];
  for (int i = 0; i < t; i++) {
    cin >> str[i];
    clog << str[i] << " : str \n";
  }

  // process
  for (int i = 0; i < t; i++) {
    int strict = 0;
    int score = 0;
    for (const char &c : str[i]) {
      if (c == 'O') {
        score += strict + 1;
        strict++;
      } else {
        strict = 0;
      }
    }
    cout << score << '\n';
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