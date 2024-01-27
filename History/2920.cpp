// 240127 6 #2920
#include <iostream>
#include <string>
using namespace std;

void body() {
  // input
  int n[8];
  for (int i = 0; i < 8; i++) {
    cin >> n[i];
  }

  // def flag
  int flag;
  if (n[1] - n[0] == 1) {
    flag = 1; // asc = 1
  } else if (n[1] - n[0] == -1) {
    flag = 2; // desc = 2
  } else {
    flag = 0; // mixed = 0
  }

  // check
  for (int i = 1; i < 8; i++) {
    if (flag == 0)
      break;

    clog << i << ':' << n[i] - n[i - 1] << ' ';

    if (flag == 1 && n[i] - n[i - 1] == 1) {

    } else if (flag == 2 && n[i] - n[i - 1] == -1) {

    } else {
      flag = 0;
      break;
    }
  }

  // output
  switch (flag) {
  case 0:
    cout << "mixed";
    break;
  case 1:
    cout << "ascending";
    break;
  case 2:
    cout << "descending";
    break;
  default:
    cerr << "err";
  }
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