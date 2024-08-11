// 240811 1 #1991
// Class 4
// 00:50
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class my {
  int nodeN;
  vector<vector<char>> tree;

  // Use Stack, FIFO
  void Preorder() {
    stack<char> travesal = {};
    char current = 'A';
    travesal.push(current);

    while (!travesal.empty()) {
      current = travesal.top();
      travesal.pop();
      cout << current;

      // load children
      for (int i = 1; i >= 0; i--) {
        char child = tree[current - 'A'][i];
        if (child != '.')
          travesal.push(child);
      }
    }

    cout << '\n';
  }

  // left root right
  void Inorder() {
    stack<char> travesal = {};
    vector<bool> isAdded(26, false);
    char current = 'A';
    travesal.push(current);
    isAdded[current - 'A'] = true;

    while (!travesal.empty()) {
      current = travesal.top();

      // left
      const char left = tree[current - 'A'][0];
      if (left != '.') {
        if (!isAdded[left - 'A']) {
          travesal.push(left);
          isAdded[left - 'A'] = true;
          continue;
        }
      }

      // root
      travesal.pop();
      cout << current;

      // right
      const char right = tree[current - 'A'][1];
      if (right != '.') {
        if (!isAdded[right - 'A']) {
          travesal.push(right);
          isAdded[right - 'A'] = true;
        }
      }
    }
    cout << '\n';
  }

  // Use stack, FIFO
  void Postorder() {
    stack<char> travesal = {};
    vector<bool> isPushed(26, false);
    char current = 'A';
    travesal.push(current);

    while (!travesal.empty()) {
      current = travesal.top();

      if (isPushed[current - 'A']) {
        travesal.pop();
        cout << current;
      }

      else {
        for (int i = 1; i >= 0; i--) {
          char child = tree[current - 'A'][i];
          if (child != '.')
            travesal.push(child);
        }
        isPushed[current - 'A'] = true;
      }
    }

    cout << '\n';
  }

public:
  void body() {
    cin >> nodeN; // [1, 26]

    // Make Tree
    tree.resize(26, vector<char>(2, '.'));

    // tree[parent][0] = left, [parent[1] = right
    for (int i = 1; i < nodeN; i++) {
      char parent, left, right;
      cin >> parent >> left >> right;
      tree[parent - 'A'][0] = left;
      tree[parent - 'A'][1] = right;
    }

    // output
    Preorder();
    Inorder();
    Postorder();
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