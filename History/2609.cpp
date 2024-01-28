// 240128 4 #2609
#include <iostream>
#include <string>
using namespace std;
int gcdf(int a, int b) {
  while (1) {
    int temp;
    if (a > b) {
      temp = a % b;
      if (temp == 0) {
        break;
      }
      a = temp;
    } else {
      temp = b % a;
      if (temp == 0) {
        break;
      }
      b = temp;
    }
  }
  return min(a, b);
}

int lcmf(int a, int b, int gcd) {
  int re = a * b / gcd;
  return re;
}

void body() {
  // input
  int a, b;
  cin >> a >> b;

  // process
  int gcd, lcm; // gcd : 최대공약수, lcm : 최소공배수
  gcd = gcdf(a, b);
  lcm = lcmf(a, b, gcd);

  // ouput
  cout << gcd << '\n' << lcm;
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