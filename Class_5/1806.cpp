// 240911 1 #1806
// Class 5
// 00:20
#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 200000
using namespace std;

class my {
  int N, target;

public:
  void body() {
    /* INPUT */
    cin >> N >> target; // [10, 100000), (0, 100000000]
    vector<int> subseq(N);

    cin >> subseq[0];
    for (int i = 1; i < N; i++) {
      int input_tmp;
      cin >> input_tmp; // [1, 10000] << 10000 * 100000 < 2^30
      subseq[i] = subseq[i - 1] + input_tmp;
    }

    // find min length : O(N^2)

    /**
     * select 1st elem starting from the behind.
     * select 2nd elem starting from 0, to first-1
     * if it is not able, break that loop
     */
    int minLength = MAX;
    for (int first = N - 1; first > 0; first--) {
      // don't need to check the same or longer length than minLength : +1
      int second_start = max(0, (first - minLength) + 1);
      for (int second = second_start; second < first; second++) {
        int sum = subseq[first] - subseq[second];

        if (sum < target)
          break;

        else
          minLength = min(minLength, first - second);
      }
    }

    if (minLength == MAX)
      cout << 0;
    else
      cout << minLength;
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
