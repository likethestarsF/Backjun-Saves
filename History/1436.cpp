// 240205 4 #1436
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void body() {
  // input
  int n;
  cin >> n;

  //  process
  int cnt = 0;
  int answer = 0;

  // Bruteforce for 666.
  for (int i = 666;; i++) {
    // find 666 in string i.
    string iStr = to_string(i);
    if (iStr.find("666") != string::npos)
      cnt++;

    // exit condition.
    if (cnt == n) {
      answer = i;
      break;
    }
  }
  // output
  cout << answer;
}

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  body();
}