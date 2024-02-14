// 240214 4 #11724
/* Graph by adjacent list
** undirected
*/
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class linking {
  int n, m;
  vector<vector<int>> list;

public:
  int nComponent = 0;
  linking() {
    cin >> n >> m;
    list = vector<vector<int>>(n, vector<int>({}));
  }

  void input() {
    for (int i = 0; i < m; i++) {
      int n1, n2;
      cin >> n1 >> n2;

      // vertex starts from 1 but vector starts from 0 -1 to vertex
      list[n1 - 1].push_back(n2 - 1);
      list[n2 - 1].push_back(n1 - 1);
    }
  }

  void countConnectedComponent() {
    vector<bool> used(n, 0); // index is equal to num - 1

    for (int i = 0; i < n; i++) {
      if (list[i].empty()) {
        nComponent++;
        used[i] = true;
        continue;
      }
      if (used[i]) {
        continue;
      } else {
        // DFS used will be true when pushes
        nComponent++;

        // initialize searchList
        stack<int> searchList = {};
        for (const auto &elem : list[i]) {
          searchList.push(elem);
          used[elem] = true;
        }

        // DFS by stack - loop
        while (!searchList.empty()) {
          // pop a data
          int check = searchList.top();
          searchList.pop();

          // search for popped data
          for (const auto &elem : list[check]) {
            if (!used[elem]) {
              searchList.push(elem);
              used[elem] = true;
            }
          }
        }
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

  linking a;
  a.input();
  a.countConnectedComponent();
  cout << a.nComponent;
}