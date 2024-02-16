// 240214 6 #1927
// 240216 1 #1927
#include <algorithm>
#include <iostream>
#include <vector>
#define HEAP_MAX 100000
using namespace std;

class heap {
  int v[HEAP_MAX + 1];
  int heap_count = 0;

  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

public:
  void input() {
    int n;
    cin >> n;

    while (n--) {
      unsigned int inp;
      cin >> inp;

      if (inp == 0) {
        pop();
      }

      else {
        push(inp);
      }
    }
  }

  void pop() {
    if (heap_count == 0) {
      cout << 0 << '\n';
      return;
    }

    // print
    cout << v[1] << '\n';

    // erase
    swap(&v[1], &v[heap_count]);
    heap_count--;

    // rebuild the heap
    int parent = 1;
    int child = parent * 2;
    if (child + 1 <= heap_count) {
      child = (v[child] < v[child + 1]) ? child : child + 1;
    }

    while (child <= heap_count && v[parent] > v[child]) {
      swap(&v[child], &v[parent]);

      parent = child;
      child = parent * 2;
      if (child + 1 <= heap_count) {
        child = (v[child] < v[child + 1]) ? child : child + 1;
      }
    }
  }

  void push(const int &inp) {
    v[++heap_count] = inp;

    int child = heap_count;
    int parent = child / 2;

    while (child > 1 && v[child] < v[parent]) {
      swap(&v[child], &v[parent]);
      child = parent;
      parent = child / 2;
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

  heap a;
  a.input();
}