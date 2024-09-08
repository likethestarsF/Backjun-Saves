// 240907 3 #2467
// 240908 1 #2467
// Class 5
// 00:50
#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

class my {
  int N;
  int minDiff = 1000000001;
  pair<int, int> selected = {0, 0};

  int binarySearch(const int &pos, const vector<int> &list) {
    int lbd = 0, rbd = list.size() - 1;
    int minDiff = pos;
    int minElem = -1;

    while (lbd <= rbd) {
      int mid = (lbd + rbd) / 2; // left one is selected always
      int diff = pos + list[mid];
      if (minDiff > abs(diff)) {
        minDiff = abs(diff);
        minElem = list[mid];
      }

      if (diff == 0)
        return list[mid];

      else if (diff > 0) {
        /*
        pos is bigger than neg from list
        -> b should be bigger
        -> lb should be mid + 1.
        */
        lbd = mid + 1;

      }

      else {
        /*
        neg from list is bigger than a
        -> b should be smaller
        -> rb should be mid - 1.
        */
        rbd = mid - 1;
      }
    }

    return minElem;
  }

  void updateGlobalMin(const int &first, const int &second) {
    int diff = first + second;

    if (minDiff > abs(diff)) {
      minDiff = abs(diff);
      selected = {first, second};
    }
  }

public:
  void body() {
    /* INPUT */
    cin >> N;
    vector<int> solute(N);
    for (int i = 0; i < N; i++) {
      cin >> solute[i]; // [-1,000,000,000, 1,000,000,000]
    }

    /**
     * Find the 0 - closest with Binary Search
     */
    for (int i = 0; i < N; i++) {
      // select 1st elem
      int first = solute[i];

      // select 2nd elem with B.S.
      int lbd = i + 1, rbd = N - 1;

      while (lbd <= rbd) {
        int mid = (lbd + rbd) / 2;
        int second = solute[mid];
        int diff = first + second;

        if (diff == 0) {
          cout << first << " " << second;
          return;
        }

        else if (diff < 0) {
          lbd = mid + 1;
          updateGlobalMin(first, second);
        }

        else /* (diff > 0) */ {
          rbd = mid - 1;
          updateGlobalMin(first, second);
        }
      }
    }

    // print
    cout << selected.first << " " << selected.second;
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
