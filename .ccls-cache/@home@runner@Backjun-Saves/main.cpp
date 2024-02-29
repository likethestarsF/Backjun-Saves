// 240229 2 #5525
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct node {
  int length;
  bool nextIsI;
};

class my {
  int nForP;
  int length;
  char c;

public:
  int cnt = 0;
  void input() {
    cin >> nForP;
    cin >> length;
  }

  // c is only I or O
  // We have to Find IOIOI...
  // Length of P = 2*n + 1
  // I : true / O : false

  void inputChar() {
    queue<node> checkList = {};
    for (int i = 0; i < length; i++) {
      cin >> c;
      bool isI = (c == 'I') ? true : false;

      // check for all nodes that we have
      if (!checkList.empty()) {
        int repeat = checkList.size();

        while (repeat--) {
          node current = checkList.front();
          checkList.pop();

          if (current.nextIsI == isI) {
            if (current.length == 1)
              cnt++;
            else {
              bool next;
              if (current.nextIsI)
                next = false;
              else
                next = true;
              checkList.push({current.length - 1, next});
            }
          }
        }
      }

      // insert new node to checkList
      if (isI) {
        node newNode = {2 * nForP, false};
        checkList.push(newNode);
      }

    } // for end
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  std::clog.setstate(std::ios_base::failbit);

  my a;
  a.input();
  a.inputChar();
  cout << a.cnt;
}