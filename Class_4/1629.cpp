// 240806 5 #1629
// Class 4
// 00:
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define ll int

class my {
  ll A, B, C;

public:
  void body() {
    cin >> A >> B >> C; // [every positive int]

    /*
     A * B mod C = (A mod C * B mod C) mod C
     Ref. the mathmatics info. from Khan Academy.
     transfer A^B into A^1 , A^2, A^4 ... and so on
     B has to be expressed in a binary form.
    */

    // Translate B into binary form
    vector<bool> B_binary(31, false); // 2^31 - 1 = 2147483647
    ll digit = 1 << 30;
    for (int i = B_binary.size() - 1; i >= 0; i--) {
      if (B - digit >= 0) {
        B -= digit;
        B_binary[i] = true;
      }
      digit = digit >> 1;
    }

    // Store A^1, A^2, A^4 ... mod C
    vector<ll> A_mod_C(31, 0);
    A_mod_C[0] = A % C;
    for (int i = 1; i < 31; i++)
      A_mod_C[i] = ((A_mod_C[i - 1] % C) * (A_mod_C[i - 1] % C)) % C;

    // Find the answer
    ll answer = 1;
    for (int i = 0; i < 31; i++) {
      if (B_binary[i] == true) {
        answer *= A_mod_C[i];
        answer %= C;
      }
    }

    cout << answer;
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