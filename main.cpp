// 240216 4 #9095
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct ott {
  int k[4] = {0, 0, 0, 0};
};

class my {

public:
  vector<int> cnt;
  void input(int t) {
    while (t--) {
      int n;
      cin >> n;

      body(n);
    }
  }

  // reset index when it reaches the end of the vector
  bool resetIndexNeeded(const vector<int> &N, int &index) {
    if (index == N.size())
      return true;
    else
      return false;
  }

  void body(const int &n) {
    int sum = 1;
    if (n == 1) {
    } else {
      // make the possible cases - DPtable
      set<ott> cases;

      //  sum of min
      vector<int> minN(n, 1);
      int minIndex = 0;
      ott minCnt;
      while (minN.back() != 1) { // 'til back is not 1

        minN.pop_back(); // remove 1
        while (true) {
          if (minN[minIndex] != 3) {
            minN[minIndex]++;
            minIndex++;
            break;
          }
          minIndex++;
          if (resetIndexNeeded(minN, minIndex)) {
            // this is the terminal case.
            minN.push_back(1);
            break;
          }
        }

        // reset index when it reaches the end of the vector
        if (resetIndexNeeded(minN, minIndex))
          minIndex = 0;

        // save the case
        for (int i = 0; i < minN.size(); i++) {
          minCnt.k[minN[i]]++;
        }

        // sort(minN.begin(), minN.end(), greater<int>()); // min goes back
      }

      // sum of max
      vector<int> maxN(n, 1);
      int maxIndex = 0;
      while (maxN.back() != 1) { // 'til back is not 1

        sort(maxN.begin(), maxN.end(), greater<int>()); // min goes back
      }
    }
    // end of count
    cnt.push_back(sum);
  }

  void output() {
    for (const auto &elem : cnt) {
      cout << elem << '\n';
    }
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
  int t;
  cin >> t;
  a.input(t);
}