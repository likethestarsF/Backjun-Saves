// 240214 3 #2606
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class network {
  int nComputer;
  int nLink;
  vector<vector<bool>> links;
  vector<bool> virus;

public:
  network() {
    cin >> nComputer; // [1, 100]
    links = vector<vector<bool>>(nComputer, vector<bool>(nComputer, 0));
    virus = vector<bool>(nComputer, 0);
    virus[0] = true;
    // elems must be decreased by 1;
  }

  void input() {
    cin >> nLink;
    for (int i = 0; i < nLink; i++) {
      int p1, p2;
      cin >> p1 >> p2;
      links[p1 - 1][p2 - 1] = true;
      links[p2 - 1][p1 - 1] = true;
    }
  }

  void wormBFS() {
    // start from pc 1. (index is defined by 0)
    queue<int> list;
    list.push(0);

    while (!list.empty()) {
      int PC = list.front();
      list.pop();

      for (int i = 0; i < nComputer; i++) {
        if (links[PC][i] == 1) {
          links[PC][i] = 0;
          links[i][PC] = 0;

          if (!virus[i]) {
            virus[i] = true;
            list.push(i);
          }
        }
      }
    }
  }

  void output() {
    int sum = -1; // exclude pc1
    for (const auto &elem : virus) {
      if (elem == true)
        sum++;
    }
    cout << sum;
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  network a;
  a.input();
  a.wormBFS();
  a.output();
}