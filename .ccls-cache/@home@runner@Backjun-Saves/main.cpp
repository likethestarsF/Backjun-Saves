// 240303 1 #7662
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// comparator function to make min heap : from geeksforgeeks
struct greaters {
  bool operator()(const long &a, const long &b) const { return a > b; }
};

class my {
  int nOfCmds;
  vector<long> maxHeap = {};
  vector<long> minHeap = {};
  multiset<long> deletedFromMax = {};
  multiset<long> deletedFromMin = {};
  int cntI = 0, cntD = 0;

  void pushMax(const long &x) {
    maxHeap.push_back(x);
    push_heap(maxHeap.begin(), maxHeap.end());
  }
  void pushMin(const long &x) {
    minHeap.push_back(x);
    push_heap(minHeap.begin(), minHeap.end(), greaters());
  }

public:
  my() {
    // initialize Heap
    maxHeap.reserve(1000000);
    minHeap.reserve(1000000);
    make_heap(maxHeap.begin(), maxHeap.end());
    make_heap(minHeap.begin(), minHeap.end(), greaters());
  }

  void makeQueue() {
    cin >> nOfCmds;
    for (int i = 0; i < nOfCmds; i++) {
      char DI;
      long n;
      cin >> DI >> n;

      exeCmd(DI, n);
    }
  }

  void exeCmd(const char &DI, const long &n) {
    if (DI == 'I') {
      pushMax(n);
      pushMin(n);
      cntI++;
    }

    else if (DI == 'D') {
      if (n == 1) { // Delete Max
        if (maxHeap.size() > 0) {
          pop_heap(maxHeap.begin(), maxHeap.end());
          deletedFromMax.insert(maxHeap.back());
          maxHeap.pop_back();
          cntD++;
        }
      } else { // Delete Min
        if (minHeap.size() > 0) {
          pop_heap(minHeap.begin(), minHeap.end(), greaters());
          deletedFromMin.insert(minHeap.back());
          minHeap.pop_back();
          cntD++;
        }
      }
    }

    else // Input ERR
      cerr << "err:exeCmd input" << endl;
  }

  void findMinMax() {
    const int delta = cntI - cntD;
    if (delta <= 0 || maxHeap.empty() || minHeap.empty()) {
      cout << "EMPTY\n";
      return;
    }

    // PRUNE OF 2 HEAPS
    vector<long> newMin = {};
    auto sizeOfMin = minHeap.size();
    /* If elem of minHeap exist in deletedFromMax
    ** 1. delete it from deletedFromMax,
    ** 2. If not, push it to new maxHeap
    ** to avoid error that happens while erasing when using index i
    */
    for (int i = 0; i < sizeOfMin; i++) {
      if (deletedFromMax.find(minHeap[i]) != deletedFromMax.end()) {
        deletedFromMax.erase(deletedFromMax.find(minHeap[i]));
      } else {
        newMin.push_back(minHeap[i]);
      }
    }
    minHeap.clear(); // we don't need it anymore

    // Totally same as above
    vector<long> newMax = {};
    auto sizeOfMax = maxHeap.size();
    for (int i = 0; i < sizeOfMax; i++) {
      if (deletedFromMin.find(maxHeap[i]) != deletedFromMin.end()) {
        deletedFromMin.erase(deletedFromMin.find(maxHeap[i]));
      } else {
        newMax.push_back(maxHeap[i]);
      }
    }
    maxHeap.clear();

    // compare squeezed heap's size and the delta
    // then remove more elem in
    sort(newMax.begin(), newMax.end(), greaters()); // front is the biggest
    sort(newMin.begin(), newMin.end(), greaters()); // back is the smallest

    for (int i = 0; i < deletedFromMax.size(); i++) {
      newMax.pop_back();
    }
    for (int i = 0; i < deletedFromMin.size(); i++) {
      newMin.pop_back();
    }

    long max = newMax.front();
    long min = newMin.back();

    cout << max << ' ' << min << '\n';
  }

  void test() {
    clog << "maxHeap:" << endl;
    for (auto i : maxHeap) {
      clog << i << ' ';
    }
    clog << "\nminHeap:" << endl;
    for (auto i : minHeap) {
      clog << i << ' ';
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
    a.findMinMax();
    // a.test();
  }
}