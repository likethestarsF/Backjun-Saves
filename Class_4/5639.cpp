// 240820 2 #5639
// 240821 1 #5639
// Class 4
// 00:00
#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 1000000000
using namespace std;

class my {
  vector<int> elems = {};
  vector<int> tree;

  // left = root*2, right = root*2+1

  void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
  }

  void Insertion(const int &key, const int &rootIdx) {
    if (tree[rootIdx] == -1) {
      tree[rootIdx] = key;
      return;
    }

    if (key > tree[rootIdx])
      Insertion(key, rootIdx * 2 + 1);
    else if (key < tree[rootIdx])
      Insertion(key, rootIdx * 2);
    else
      return;
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
    /* Input */
    while (true) {
      int input;
      cin >> input;

      // test exit
      if (input == -1)
        break;

      if (cin.eof())
        break;
      elems.push_back(input);
    }
    /* Main */
    // Idx of Binary tree starts from 1
    tree.resize(10, -1);
    tree[0] = -1;
    // make the tree
    for (int i = 1; i < elems.size() + 1; i++)
      // Insertion(elems[i], 1)
      ;
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