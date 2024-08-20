// 240820 2 #5639
// Class 4
// 00:00
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class my {
  vector<int> tree;
  // left = root*2, right = root*2+1

  void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
  }
  void Sorting() {
    const int maxIdx = tree.size() - 1;
    int curIdx = maxIdx;

    /**
     * 1. compare with the parent
     * 2. swap if child is bigger than parent
     * 3. else parent is bigger than child, break.
     * 4. or cur is root, break.
     */
    while (true) {
      if (curIdx == 1)
        break;

      if (tree[curIdx] > tree[curIdx / 2]) {
        swap(tree[curIdx], tree[curIdx / 2]);
        curIdx /= 2;
      }

      else
        break;
    }
  }

public:
  void body() {
    // Idx of Binary tree starts from 1
    tree.resize(1, -1);

    /* Input */
    while (true) {
      int input;
      cin >> input;
      if (cin.eof())
        break;
      tree.push_back(input);
      Sorting();

      // test exit
      if (input == -1)
        break;
    }
    /* Main */
    // make the
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
  a.body();
}