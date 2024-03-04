// 240305 3 #11279
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// MaxHeap
class my {
  vector<long> heap;

public:
  my() {
    heap.reserve(100001);
    // heap doesn't use index 0
    heap.push_back(-1);
  }

  void command(long &n) {
    if (n == 0) {
      pop();
    } else {
      push(n);
    }
  }

  void pop() {
    // 1. No elem
    if (heap.size() == 1) {
      cout << 0 << '\n';
      return; // EXIT
    }

    cout << heap[1] << '\n';

    // 2. Only one elem exists
    if (heap.size() == 2) {
      heap.pop_back();
      return; // EXIT
    }

    // 3. General cases
    // move last elem to root
    swap(heap[1], heap.back()); // can not work well because of swap
    heap.pop_back();

    organizeForPop(); // compare start from the root
  }

  void push(long &n) {
    heap.push_back(n);

    organizeForPush(); // compare start from the back of heap
  }

  void organizeForPop() {
    /* COND-start from the root
    **: parent = 1
    ** 0. compare parent and the children
    ** 1. if parent is bigger than children, that is the end.
    ** 1-1. if there's no children, that is the end too.
    ** 2. if a child is bigger than parent, swap parent and child
    ** 2-2. swapped child became the parent
    **and compare again with the children.
    */
    int parent = 1;
    int childL, childR;

    while (true) {
      childL = 2 * parent;
      childR = 2 * parent + 1;

      // no child: EXIT
      if (childL > heap.size() - 1)
        break; // EXIT 1-1.

      // only childL exists
      if (childL == heap.size() - 1) {
        if (heap[parent] < heap[childL]) {
          swap(heap[parent], heap[childL]);
          parent = childL;
        } else
          break; // EXIT : 1.
      }

      // two children exist but parents are the biggest: EXIT
      else if (heap[parent] >= heap[childL] && heap[parent] >= heap[childR]) {
        break; // EXIT 1.
      }

      // two children exist and parents are not the biggest
      else {
        if (heap[childL] > heap[childR]) {
          swap(heap[parent], heap[childL]);
          parent = childL;
        } else {
          swap(heap[parent], heap[childR]);
          parent = childR;
        }
      }
    }
  }

  void organizeForPush() {
    /* COND-start from the back
    **: child = heap.size()
    ** 0. compare parent and the children
    ** 1. parent must not be less than 1
    ** 1-2. if parent is bigger than or equal to children, that is the end.
    ** 2. if a child is bigger than parent, swap parent and child
    ** 2-2. swapped parent became the child
    **and compare again with the parent.
    */
    int child = heap.size() - 1;
    int parent;

    while (true) {
      parent = child / 2;

      if (parent < 1)
        break; // EXIT 1.

      if (heap[child] <= heap[parent])
        break; // EXIT 1-2.

      else {
        swap(heap[child], heap[parent]);
        child = parent;
      }
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
  while (t--) {
    long n;
    cin >> n;
    a.command(n);
  }
}