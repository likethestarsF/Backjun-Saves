// 240218 3 #18870
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct intint {
  int value;
  int order;
  int compressed;
};

bool compareByValue(const intint &a1, const intint &a2) {
  return a1.value < a2.value;
}

bool compareByOrder(const intint &a1, const intint &a2) {
  return a1.order < a2.order;
}

class my {
  vector<int> xList;
  int listSize;

public:
  void input(const int &n) {
    // init the vector
    xList = vector<int>(n);
    listSize = n;

    for (int i = 0; i < n; i++) {
      int inp;
      cin >> inp;
      xList[i] = inp;
    }
  }

  // cf. Internet description about coordinate compression
  void coordiniateComp() {
    vector<int> xList_cp = xList;
    sort(xList_cp.begin(), xList_cp.end());

    // delete duplicated values
    xList_cp.erase(unique(xList_cp.begin(), xList_cp.end()), xList_cp.end());

    for (int i = 0; i < listSize; i++) {
      int index = lower_bound(xList_cp.begin(), xList_cp.end(), xList[i]) -
                  xList_cp.begin();

      cout << index << ' ';
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

  int n;
  cin >> n;
  my a;
  a.input(n);
  a.coordiniateComp();
}