// 240229 2 #5525
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct node {
  int length;
  char next;
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

  void inputChar() {
    queue<node> checkList = {};
    for (int i = 0; i < length; i++) {
      cin >> c;
      clog << "C : " << c << endl;

      // insert new node to checkList
      if (c == 'I') {
        node newNode = {2 * nForP + 1, 'I'};
        checkList.push(newNode);
      }

      else if (c == 'O') {
      } else {
        clog << "error" << endl;
      }

      if (checkList.empty())
        continue;

      // check for all nodes that we have
      else {
        int repeat = checkList.size();

        while (repeat--) {
          node current = checkList.front();
          checkList.pop();

          if (current.length == 0) {
            clog << "Case confirm" << endl;
            cnt++;
          }

          else if (current.next == c) {
            char next;
            if (current.next == 'I')
              next = 'O';
            else
              next = 'I';

            checkList.push({current.length - 1, next});
            clog << "push: " << current.length - 1 << " " << next << endl;
          }

          else { // erase wrong node : do not push
            clog << "erase wrong case" << endl;
          }
        }
      }
    }

    // last check if there is 0
    if (!checkList.empty()) {
      int repeat = checkList.size();
      while (repeat--) {
        node current = checkList.front();
        checkList.pop();

        if (current.length == 0) {
          cnt++;
        };
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
  std::clog.setstate(std::ios_base::failbit);

  my a;
  a.input();
  a.inputChar();
  cout << a.cnt;
}