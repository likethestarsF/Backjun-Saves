// 240820 2 #5639
// 240821 1 #5639
// Class 4
// 01:50
#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 1000000000
using namespace std;

class my {
  vector<int> elems = {};
  struct node {
    int data;
    struct node *left, *right;
    struct node *parent;
  };

  struct node *newNode(int key) {
    struct node *temp = new node;
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
  }

  struct node *Insertion(const int &key, struct node *root) {
    // Make New Node
    if (root == NULL)
      return newNode(key);

    if (key > root->data)
      root->right = Insertion(key, root->right);
    else if (key < root->data)
      root->left = Insertion(key, root->left);
    return root;
  }

  void Postorder(struct node *root) {
    if (root == NULL)
      return;

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << '\n';
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
    // make the tree
    node root = {elems[0], NULL, NULL};
    for (int i = 1; i < elems.size(); i++)
      Insertion(elems[i], &root);
    elems.clear();

    // travel the tree
    Postorder(&root);
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