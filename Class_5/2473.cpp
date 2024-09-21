// 240921 1 #2473
// Class 5
// 01:00
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define INF 5e9
#define ll long long
using namespace std;

class MY {
  int solutionN;
  vector<ll> solution;
  vector<ll> result;

  void updateGlobalMin(ll &globalMin, ll localMin, ll a, ll b, ll c) {
    if (abs(globalMin) > abs(localMin)) {
      globalMin = localMin;

      result[0] = a;
      result[1] = b;
      result[2] = c;
    }
  }

  void printResult(ll a, ll b, ll c) { cout << a << ' ' << b << ' ' << c; }

public:
  MY() {
    /* Input */
    cin >> solutionN;
    solution.resize(solutionN);
    for (int i = 0; i < solutionN; i++)
      cin >> solution[i];
    sort(solution.begin(),
         solution.end()); // inc. order

    result.resize(3, 0);
  }

  /**
   * 1. select the 1st one. Sequentially: O(N)
   * 2. select 2nd & 3rd with Two Ptr: O(N)
   * -> O(N^2)
   * 3. Sum 1st + 2nd & 3rd,
   * 3-1. if sum > 0, ptrR - 1
   * 3-2. if sum < 0, ptL + 1
   * 3-3. if sum = 0, print the result, Permanent exit
   * sum_MAX = 1e9*3 > 2^31; use ll
   */
  void body() {
    ll globalMin = INF;
    for (int i = 0; i < solutionN - 2; i++) {
      // 1
      ll *first = &solution[i];

      // 2
      int ptrL = i + 1, ptrR = solutionN - 1;

      while (ptrL < ptrR) {
        ll *second = &solution[ptrL];
        ll *third = &solution[ptrR];
        const ll localSum = *first + *second + *third;

        // 3-3
        if (localSum == 0) {
          printResult(*first, *second, *third);
          exit(0);
        }

        // update globalMin
        updateGlobalMin(globalMin, localSum, *first, *second, *third);

        // 3-1
        if (localSum > 0)
          ptrR--;

        // 3-2
        else if (localSum < 0)
          ptrL++;
      }
    }

    /* Output */
    printResult(result[0], result[1], result[2]);
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  MY my;
  my.body();
}
