// 240128 3 #1259
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void body() {
  while (1) {
    // input
    string n;
    cin >> n;
    if (n == "0") {
      break;
    }

    // process
    bool tf = 1;
    int len = n.length();
    for (int i = 0; i < len / 2; i++) {
      if (n[i] != n[len - 1 - i]) {
        tf = 0;
        break;
      }
    }

    // output
    tf ? cout << "yes\n" : cout << "no\n";
  }
}

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  std::clog.setstate(std::ios_base::failbit);

  body();
}