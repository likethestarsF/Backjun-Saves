#include <iostream>
#include <string>
using namespace std;

void body() {
  int inp;
  int res = 1;

  for (int i = 0; i < 3; i++) {
    cin >> inp;
    res *= inp;
  }
  clog << res << endl;

  string str = to_string(res);
  int index[10] = {0};

  // '0' = 48
  for (const char &c : str) {
    int a = (int)c - 48;
    index[a] += 1;
    clog << "clog a " << a << " " << index[a] << endl;
  }
  for (int i = 0; i < 10; i++) {
    cout << index[i] << '\n';
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