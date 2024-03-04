// 240303 1 #7662
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class my {
  int nOfCmds;
  map<long, int> mapElem = {};

public:
  priority_queue<long, vector<long>, greater<long>> minHeap = {};
  priority_queue<long, vector<long>, less<long>> maxHeap = {};

  void makeQueue() {
    cin >> nOfCmds;
    for (int i = 0; i < nOfCmds; i++) {
      char DI;
      long n;
      cin >> DI >> n;

      exeCmd(DI, n);
    }
  }

  void insert(const long &val) {
    minHeap.push(val);
    maxHeap.push(val);

    if (mapElem.find(val) == mapElem.end()) {
      mapElem.insert({val, 1});
    } else {
      mapElem[val]++;
    }
  }

  void DelMax() {
    if (maxHeap.empty())
      return; // exception

    while (!maxHeap.empty() && mapElem.find(maxHeap.top()) == mapElem.end()) {
      maxHeap.pop();
    }

    if (maxHeap.empty())
      return; // exception

    long val = maxHeap.top();
    maxHeap.pop();

    // update mapElem
    mapElem[val]--;
    // remove key if value is 0
    if (mapElem.find(val) != mapElem.end() && mapElem[val] == 0) {
      mapElem.erase(val);
    }
  }
  // totally same as above
  void DelMin() {
    if (minHeap.empty())
      return;

    while (!minHeap.empty() && mapElem.find(minHeap.top()) == mapElem.end()) {
      minHeap.pop();
    }

    if (minHeap.empty())
      return;

    long val = minHeap.top();
    minHeap.pop();

    mapElem[val]--;
    if (mapElem.find(val) != mapElem.end() && mapElem[val] == 0) {
      mapElem.erase(val);
    }
  }

  void exeCmd(const char &DI, const long &n) {
    if (DI == 'I') {
      insert(n);
    }

    else if (DI == 'D') {
      if (n == 1) { // Delete Max
        DelMax();
      } else if (n == -1) { // Delete Min
        DelMin();
      }
    }
  }

  template <typename T> void clean(T &heap) {
    while (!heap.empty() && mapElem.find(heap.top()) == mapElem.end()) {
      heap.pop();
    }
  }

  void output() {
    clean(minHeap);
    clean(maxHeap);

    if (minHeap.empty() || maxHeap.empty()) {
      cout << "EMPTY\n";
      return;
    }

    long max = maxHeap.top();
    long min = minHeap.top();
    cout << max << ' ' << min << '\n';
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
  }
}