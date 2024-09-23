// 240924 1 #1202
// Class 5
// 00:00
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 2147483647
using namespace std;

class MY {
  struct jewel {
    int weight, value;

    static bool compare(const jewel &a, const jewel &b) {
      return a.value / a.weight > b.value / b.weight;
    }
  };

  int jewelNum, bagNum;    // [,3e5]
  vector<int> bag;         // [,1e8]
  vector<jewel> jewelList; // [,1e6]

public:
  MY() {
    /* Input */
    cin >> jewelNum >> bagNum;
    jewelList.resize(jewelNum);
    bag.resize(bagNum);

    for (int i = 0; i < jewelNum; i++)
      cin >> jewelList[i].weight >> jewelList[i].value;
    for (int i = 0; i < bagNum; i++)
      cin >> bag[i];
  }

  void body() {
    // 'value/weight': decreasing order
    sort(jewelList.begin(), jewelList.end(), jewel::compare);
    sort(bag.begin(), bag.end());

    long long maxValue = 0; // 3e5*1e6 > 2^31
    for (int i = 0; i < bagNum; i++) {
      // select a jewel for the bag
      for (int idxJ = 0; idxJ < jewelList.size(); idxJ++) {
        if (bag[i] >= jewelList[idxJ].weight) {
          maxValue += jewelList[idxJ].value;
          jewelList.erase(jewelList.begin() + idxJ);
          break;
        }
      }
    }

    cout << maxValue;
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
