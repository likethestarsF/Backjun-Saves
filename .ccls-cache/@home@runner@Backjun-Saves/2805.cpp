// 240219 1 #2805// date num #eg
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {
  long treeN, length;
  vector<long> treeList;
  long result = -1;

public:
  void in() {
    cin >> treeN >> length;

    treeList = vector<long>(treeN);
    for (long i = 0; i < treeN; i++) {
      cin >> treeList[i];
    }
  }

  long long calcLength(const long &num) {
    long long sum = 0;
    for (long i = 0; i < treeList.size(); i++) {
      long partial = treeList[i] - num;
      if (partial < 0)
        partial = 0;
      sum += partial;
    }
    return sum;
  }

  void cutting() {
    sort(treeList.begin(), treeList.end());

    // Use binary search : init.
    long upperBound = treeList.back();
    long lowerBound = 0;
    long mid = (upperBound + lowerBound) / 2;

    /* GOAL: Find the biggest N that makes x >= length
    ** we find the biggest n that makes x < length
    ** then, n+1 is the biggest N
    */

    // loop until range.size is 1
    while (lowerBound < upperBound) {
      long long x = calcLength(
          mid); // f() that tells the sum of length calculated by the N
      // case 1 : x < length
      if (x < length) {
        upperBound = mid - 1;
        mid = (upperBound + lowerBound) / 2;
      }
      // case 2 : x > length
      else if (x > length) {
        lowerBound = mid + 1;
        mid = (upperBound + lowerBound) / 2;
      }
      // case 3 : x == length
      else {
        result = mid;
        break;
      }
    }

    int min = (lowerBound < upperBound) ? lowerBound : upperBound;
    min--;
    int max = (lowerBound < upperBound) ? upperBound : lowerBound;

    for (auto i = min; i <= max; i++) {
      if (calcLength(i) >= length) {
        result = i;
      } else {
        break;
      }
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
  a.in();
  a.cutting();
}