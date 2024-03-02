// 240303 1 #7662
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class my {
  struct cmpForMin {
    bool operator()(const pair<long, int> &a1,
                    const pair<long, int> &a2) const {
      return a1.first > a2.first;
    }
  };

  struct cmpForMax {
    bool operator()(const pair<long, int> &a1,
                    const pair<long, int> &a2) const {
      return a1.first < a2.first;
    }
  };

public:
  int nOfCmds;
  // priority, counter for identification
  priority_queue<pair<long, int>, vector<pair<long, int>>, cmpForMin> minHeap =
      {};
  priority_queue<pair<long, int>, vector<pair<long, int>>, cmpForMax> maxHeap =
      {};


  int indexCnt = 0;

  my() {}

  void makeQueue() {
    cin >> nOfCmds;
    for (int i = 0; i < nOfCmds; i++) {
      char DI;
      long n;
      cin >> DI >> n;

      exeCmd(DI, n);
    }
  }

  void insert(long val) {
    minHeap.push({val, indexCnt});
    maxHeap.push({val, indexCnt});
    indexCnt++;
  }

  void DelMax() {
    if (maxHeap.empty())
      return;
    auto val = maxHeap.top();
    maxHeap.pop();
    // Del Min also
    DelMintoo(val.second);
  }
  void DelMin() {
    if (minHeap.empty())
      return;
    auto val = minHeap.top();
    minHeap.pop();
    // Del Max also
    DelMaxtoo(val.second);
  }

  /* When I have to delete by index in priority_queue
  ** make temp queue and push all elements except the one to be deleted
  ** then, SWAP
  */
  void DelMintoo(int &cnt) {
    priority_queue<pair<long, int>, vector<pair<long, int>>, cmpForMin> temp =
        {};
    while (!minHeap.empty()) {
      if (minHeap.top().second != cnt) {
        temp.push(minHeap.top());
      }
      minHeap.pop();
    }
    minHeap.swap(temp);
  }
  void DelMaxtoo(int &cnt) {
    priority_queue<pair<long, int>, vector<pair<long, int>>, cmpForMax> temp =
        {};
    while (!maxHeap.empty()) {
      if (maxHeap.top().second != cnt) {
        temp.push(maxHeap.top());
      }
      maxHeap.pop();
    }
    maxHeap.swap(temp);
  }

  void exeCmd(const char &DI, const long &n) {
    if (DI == 'I') {
      insert(n);
    }

    else if (DI == 'D') {
      if (n == 1) { // Delete Max
        DelMax();
      } else if (DI == -1) { // Delete Min
        DelMin();
      }
    }
  }

  void output() {
    if (minHeap.empty() || maxHeap.empty()) {
      cout << "EMPTY\n";
      return;
    }

    long max = maxHeap.top().first;
    long min = minHeap.top().first;
    cout << max << ' ' << min << '\n';
  }

  template <typename T> void test(T v) {

    clog << "maxHeap : " << endl;
    while (!v.empty()) {
      clog << v.top().first << ' ' << v.top().second << endl;
      v.pop();
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

  int t;
  cin >> t;
  while (t--) {
    my a;
    a.makeQueue();
    a.output();
    // a.test(a.maxHeap);
  }
}