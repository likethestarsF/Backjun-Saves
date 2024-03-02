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
  int cntI = 0, cntD = 0;
  long deletedMax = LONG_MAX;
  long deletedMin = LONG_MIN;

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
          long temp = maxHeap.back();
          deletedMax = (temp < deletedMax) ? temp : deletedMax;
          maxHeap.pop_back();
          cntD++;
        }
      } else { // Delete Min
        if (minHeap.size() > 0) {
          pop_heap(minHeap.begin(), minHeap.end(), greaters());
          long temp = minHeap.back();
          deletedMin = (temp > deletedMin) ? temp : deletedMin;
          minHeap.pop_back();
          cntD++;
        }
      }
    }

    else // Input ERR
      cerr << "err:exeCmd input" << endl;
  }

  void findMinMax() {
    long min = minHeap.front();
    long max = maxHeap.front();

    if (cntI - cntD <= 0)
      cout << "EMPTY\n";
    else {
    }

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
  }
}