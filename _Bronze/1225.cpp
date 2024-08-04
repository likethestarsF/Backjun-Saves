// 240804 1 #1225
// Random Marthon 9 B
// 00:10
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class my {
  string A, B;

public:
  void body() {
    cin >> A >> B; // [0, 10^10000)

    long long aSum = 0, bSum = 0;
    for (int i_A = 0; i_A < A.length(); i_A++) {
      aSum += A[i_A] - '0'; // [, 90000]
    }
    for (int i_B = 0; i_B < B.length(); i_B++) {
      bSum += B[i_B] - '0';
    }

    cout << (long long)(aSum * bSum); // [, 90000^2]
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