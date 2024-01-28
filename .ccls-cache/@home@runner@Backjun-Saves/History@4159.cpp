// 240128 3 #4153
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void body() {
  while (1) {
    // input
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    if (a[0] == 0 && a[1] == 0 && a[2] == 0) {
      break;
    }

    // process
    sort(a, a + 3);
    clog << *a << *(a + 1) << *(a + 2) << '\n';
    bool tf = a[2] * a[2] == a[0] * a[0] + a[1] * a[1];

    // output
    tf ? cout << "right\n" : cout << "wrong\n";
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