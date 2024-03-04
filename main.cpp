// 240305 4 #11286
#include <algorithm>
#include <iostream>
#include <vector>
#define MAX_COMMAND 1000000
using namespace std;

class heap_ABS {
  struct abs {
    bool isPos;
    int value;
  };
  vector<abs> heap;

public:
  heap_ABS() {
    heap.reserve(MAX_COMMAND + 1);
    heap.push_back({0, 0}); // heap don't use index 0
  }

  void command(bool &isPos, int &value) {
    if (value == 0)
      pop();
    else {
      abs elem = {isPos, value};
      push(elem);
    }
  }

  void pop() {
    // 1. Exclude when heap is empty
    if (heap.size() == 1) {
      cout << 0 << '\n';
      return;
    }

    // 2. Exclude when only one element exists
    if (heap.size() == 2) {
      cout << heap[1].value << '\n';
      heap.pop_back();
      return;
    }

    // 3. General case
    cout << heap[1].value << '\n';
    swap(heap[1], heap.back());
    heap.pop_back();

    down_heap();
  }
  void push(abs elem) {
    heap.push_back(elem);

    up_heap();
  }

  // comparison must be done by value -> sign order

  void down_heap() { // for pop
    /* Compare parent -> children
    ** 1. Boundary Check.
    **1-1. Are Children indexs smaller than .size() -1?
    ** 2. If value of parent is smaller than children, no need to swap.
    ** 3. If value of parent is larger than children,
    **swap child becomes the parent.
    */

    int parent = 1;
    int childL;
    // int childR = childL + 1;

    while (true) {
      childL = parent * 2;

      // [1] No children exists
      if (childL > heap.size() - 1) {
        break; // EXIT: 1-1.
      }

      // [2] Only a childL exists
      else if (childL == heap.size() - 1) {
        if (heap[parent].value < heap[childL].value)
          break;

        else if (heap[parent].value == heap[childL].value) {
          if (heap[parent].isPos == false)
            break;
          else if (heap[childL].isPos == true)
            break;
          // Exclude 2 exceptions; [parent, child] : [neg, ?], [pos, pos]

          // swap and update parent
        }

        else /*(heap[parent].value > heap[childL].value)*/ {
          // swap and update parent
        }
      }

      // [3] Two Children Exists.
      else {
        // Exception 1: both of them are bigger
        if (heap[parent].value < heap[childL].value &&
            heap[parent].value < heap[childL + 1].value)
          break;

        //// Compare L and R to choose one of them as child
        int child;
        // case 1. L is smaller :> Choose L
        if (heap[childL].value < heap[childL + 1].value) {
          child = childL;
        }
        // case 2. R is smaller :> Choose R
        else if (heap[childL].value > heap[childL + 1].value) {
          child = childL + 1;
        }
        // case 3. L and R are equal.
        else {
          // Choose L case; isPos[L,R] : [0,x], [1,1]
          if (heap[childL].isPos == false)
            child = childL;
          else if (heap[childL + 1].isPos == true)
            child = childL;
          else
            child = childL + 1; //  remain cases : Choose R
        }

        //// Compare parent and child
        // case 1. parent is smaller
        if (heap[parent].value < heap[child].value)
          break;
        // case 2: both values equal
        else if (heap[parent].value == heap[child].value) {
          // Exclude 2 exceptions; [parent, child] : [neg, ?], [pos, pos]
          if (heap[parent].isPos == false)
            break;
          else if (heap[child].isPos == true)
            break;

          // swap and update parent
          swap(heap[parent], heap[child]);
          parent = child;
        }
        // case 3: parent is bigger
        else {
          // swap and update parent
          swap(heap[parent], heap[child]);
          parent = child;
        }
      }
    }
  }
  void up_heap() { // for push
    /* Compare Child -> parent
    ** 1. Boundary check for parent 
    **
    */

    int child = heap.size() - 1;
    int parent;
    while (true) {
      parent = child / 2;
      if(parent < 1)
        break;

      //case 1
      if() {}
      //case 2
      else  if() {}
      //case 3
      else {}
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

  heap_ABS a;

  int t;
  while (t--) {
    long long n;
    cin >> n;

    bool isPos;
    int value;
    if (n >= 0) {
      isPos = true;
      value = n;
    } else {
      isPos = false;
      value *= -1;
    }

    a.command(isPos, value);
  }
}