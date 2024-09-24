// 240924 1 #1202
// Class 5
// 01:30
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 2147483647
#define ll long long
using namespace std;

class MY {
  struct jewel {
    int weight, value;

    static bool weightComp(const jewel &a, const jewel &b) {
      return a.weight < b.weight;
    }
  };

  struct valueComp {
    bool operator()(const jewel &a, const jewel &b) {
      return a.value < b.value;
    }
  };

  int jewelNum, bagNum;    // [,3e5]
  vector<int> bag;         // [,1e8]
  vector<jewel> jewelList; // [0, 1e6]

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
    sort(jewelList.begin(), jewelList.end(), jewel::weightComp);
    sort(bag.begin(), bag.end());

    priority_queue<jewel, vector<jewel>, valueComp> pq;

    /** Priority Queue
     * 1. Push everything that can be handled by current bag.
     * * idx is remains even if the while() loop is ended;
     * * already pushed elems don't need to be pushed again.

     * 2. Pop the top. add its value to the sum.
     * * Since queue is sorted by the value, top is always the most valuable
     * * and the bag is sorted by weight, jewels in the queue that
     * * previous bags can handle also can be carried by latter bags.
     */

    ll sumValue = 0; // 3e5*1e6 > 2^31
    int idx = 0;
    for (int i = 0; i < bagNum; i++) {
      // 1.
      while (idx < jewelNum) {
        if (bag[i] >= jewelList[idx].weight)
          pq.push(jewelList[idx++]);
        else
          break;
      }

      // 2.
      if (!pq.empty()) {
        const int value = pq.top().value;
        pq.pop();
        sumValue += value;
      }
    }

    cout << sumValue;
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
