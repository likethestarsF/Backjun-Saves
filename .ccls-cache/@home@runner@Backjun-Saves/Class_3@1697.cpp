// 240214 2 #1697
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 100000

class hideAndSeek {
  int stalker, target;
  vector<int> coord;

public:
  hideAndSeek() {
    // if elem > -1, that location is already searched.
    coord = vector<int>(MAX + 2, 0);
    coord[MAX + 1] = 1;
  }
  void input() { cin >> stalker >> target; }

  // stalker can move 1m in 1sec.
  // or she can teleport to 2*(current-position) in 1sec.
  // find the shortest time to catch the target.
  int movePos(const int &k) {
    if (k + 1 <= MAX)
      return (k + 1);
    else
      return (MAX + 1);
  }
  int moveNeg(const int &k) {
    if (k - 1 >= 0)
      return (k - 1);
    else
      return (MAX + 1);
  }
  int moveTele(const int &k) {
    if (k * 2 <= MAX)
      return k * 2;
    else
      return (MAX + 1);
  }

  void BFS() {
    queue<int> search = {};
    search.push(stalker); // init starting

    while (!search.empty()) {
      int here = search.front();
      search.pop();

      if (here == target)
        break; // exit when find the target

      int preSearch;
      /* preSearch will be MAX+1 if it can not move. [MAX+1] is 1.
      ** == 0 means [preSearch] is not visited.
      */

      preSearch = movePos(here); // Case 1
      if (coord[preSearch] == 0) {
        search.push(preSearch);
        coord[preSearch] = coord[here] + 1;
      }

      preSearch = moveNeg(here); // Case 2
      if (coord[preSearch] == 0) {
        search.push(preSearch);
        coord[preSearch] = coord[here] + 1;
      }

      preSearch = moveTele(here); // Case 3
      if (coord[preSearch] == 0) {
        search.push(preSearch);
        coord[preSearch] = coord[here] + 1;
      }
    }
  }

  void output() { cout << coord[target]; }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  hideAndSeek a;
  a.input();
  a.BFS();
  a.output();
}