// 240803 2 #15239
// Random Marthon 9 C
// 00:40
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class my {
  int nMax;
  string symbols = "+_)(*&^%$#@!./,;{}";

  bool IsVaild(const vector<char> &pw) {
    if (pw.size() < 12)
      return false; // 5. Minimum Length is 12.

    // 1. At least 1 lower case
    // 2. At least 1 Upper case
    // 3. At least 1 digit
    // 4. At least one symbol from the set +_)(*&^%$#@!./,;{}
    bool cases[4] = {false, false, false, false};
    for (int i = 0; i < pw.size(); i++) {
      if (pw[i] >= 97 && pw[i] <= 122) // [a, z]
        cases[0] = true;

      else if (pw[i] >= 65 && pw[i] <= 90) // [A, Z]
        cases[1] = true;

      else if (pw[i] >= 48 && pw[i] <= 57) // [0, 9]
        cases[2] = true;

      else if (symbols.find(pw[i]) != string::npos) // symbols
        cases[3] = true;
    }

    for (int i = 0; i < 4; i++)
      cases[0] *= cases[i];

    return cases[0];
  }

public:
  void body() {
    cin >> nMax;

    while (nMax--) {
      int lenOfPW;
      cin >> lenOfPW;
      vector<char> pw = vector<char>(lenOfPW);
      for (int i = 0; i < lenOfPW; i++)
        cin >> pw[i];

      // # Output
      if (IsVaild(pw))
        cout << "valid" << '\n';
      else
        cout << "invalid" << '\n';
    }
  }
};
int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  my a;
  a.body();
}