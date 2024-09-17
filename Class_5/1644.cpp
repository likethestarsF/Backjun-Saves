// 240917 1 #1644
// Class 5
// 00:50
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define MAX 4000000
using namespace std;

class my {
  int x;

  vector<int> Sieve(const int &x) {
    vector<int> result = {};
    vector<int> isPrime(x + 1, true);

    for (int i = 2; i <= x; i++) {
      for (int j = i * 2; j <= x; j += i) {
        isPrime[j] = false;
      }
    }

    for (int i = 2; i <= x; i++) {
      if (isPrime[i] == false)
        continue;
      result.push_back(i);
    }

    return result;
  }

public:
  void body() {
    /* Input */
    cin >> x;

    // Find the list of the Prime Numbers : O(NloglogN)
    vector<int> primeList = Sieve(MAX);

    /**
     * Count Cases
     * 1. define the idx of end point : first idx, bigger than x
     * 2. Sum the prime numbers sequentially : O(N^2)
     * 3. Or use 2 pointers : O(N)
     * 3-1. If sum is bigger than x, move the start point to the left
     * 3-2. If sum is smaller than x, move the end point to the right
     * 3-3. If sum is equal to x, increase the cnt && move the end point
     */

    // 1
    int idxEnd = -1;
    for (int i = 0; i < primeList.size(); i++) {
      if (primeList[i] > x) {
        idxEnd = i;
        break;
      }
    }
    // primeList.resize(idxEnd);

    /* // 2
    for (int i = 0; i < idxEnd; i++) {
      int sum = 0;
      for (int j = i; j < idxEnd; j++) {
        sum += primeList[j];

        if (sum == x) {
          cnt++;
          break;
        } else if (sum > x)
          break;
      }
    }
    */

    // 3
    int cnt = 0;
    int pLeft = 0, pRight = 0;
    int sum = primeList[pLeft];
    while (pLeft <= pRight && pRight < idxEnd) {
      // 3-1
      if (sum > x) {
        sum -= primeList[pLeft];
        pLeft++;
      }

      // 3-2
      else if (sum < x) {
        pRight++;
        sum += primeList[pRight];
      }

      // 3-3
      else if (sum == x) {
        cnt++;
        pRight++;
        sum += primeList[pRight];
      }
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
