// 240917 1 #1644
// Class 5
// 01:30
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define MAX 4000000
#define ll long long
using namespace std;

class my {
  int x;

  vector<int> Sieve(const int &x) {
    vector<int> result = {};
    vector<bool> isPrime(x + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= sqrt(x); i++) {
      if (isPrime[i]) {
        for (int j = i * 2; j <= x; j += i) {
          isPrime[j] = false;
        }
      }
    }

    for (int i = 2; i <= x; i++) {
      if (isPrime[i])
        result.push_back(i);
    }

    return result;
  }

public:
  void body() {
    /* Input */
    cin >> x;

    // Find the list of the Prime Numbers : O(NloglogN)
    vector<int> primeList = Sieve(x);

    /**
     * Count Cases
     * 1. define the idx of end point : first idx, bigger than x
     * 2. Sum the prime numbers sequentially : O(N^2)
     * 3. Or use 2 pointers : O(N)
     * 3-1. If sum is bigger than x, move the start point to the left
     * 3-2. If sum is smaller than x, move the end point to the right
     * 3-3. If sum is equal to x, increase the cnt && move the end point
     */

    // 3
    int cnt = 0;
    int pLeft = 0, pRight = 0;

    ll sum = 0;
    while (pRight < primeList.size()) {
      sum += primeList[pRight];

      // 3-1
      while (sum > x && pLeft <= pRight) {
        sum -= primeList[pLeft];
        pLeft++;
      }

      // 3-3
      if (sum == x)
        cnt++;

      // 3-2
      pRight++;
    }

    cout << cnt;
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
