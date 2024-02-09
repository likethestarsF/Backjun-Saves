// 240209 6 #1929
/* Check if a number is prime number.
** Use Sieve of Eratosthenes.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void body() {
  // input
  int min, max;
  cin >> min >> max;

  //  initialize the sieve
  vector<bool> sieve(1000001, 1);
  sieve[0] = 0;
  sieve[1] = 0;

  // loop for each elements of sieve
  for (int elem = 2; elem <= max; elem++) {

    // loop to eliminate non-prime numbers: elem * i
    for (int i = 2; elem * i <= max; i++) {
      sieve[elem * i] = 0;
    }
  }

  // output
  for (int i = min; i <= max; i++)
    if (sieve[i] == 1)
      cout << i << '\n';
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