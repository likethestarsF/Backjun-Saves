// 240804 2 #14579
// Random Marthon 9 A
// 00:10
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class my {
  int a, b;

  long long sum(int a) { return ((a + 1) * a / 2); }

public:
  void body() {
    cin >> a >> b; // [1,1000]

    long long result = 1;
    for (int i = a; i <= b; i++) {
      long long temp = sum(i); // [1, (1+1000)/2*1000 = 500500]
      temp = temp % 14579;
      result = (result * temp) % 14579; // [1, 14579]
    }

    cout << result;
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