// 240914 1 #20040
// Class 5
// 00:45
#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 10000000
using namespace std;

class my {
  int dotN, phaseN;
  vector<pair<int, int>> line;
  vector<int> rank;
  vector<int> parent;

  void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
  }

  int Find(const int &x) {
    if (x == parent[x])
      return x;
    return parent[x] = Find(parent[x]);
  }

  void Union(int x, int y) {
    // load parents
    x = Find(x);
    y = Find(y);

    // already unified
    if (x == y)
      return;

    // swap, in order to always make low rank one as a subtree of high rank one
    if (rank[x] > rank[y])
      swap(x, y);

    // unify two trees into a single
    parent[x] = y;

    // make parent one's rank bigger, as rank is increased
    if (rank[x] == rank[y])
      rank[y]++;
  }

public:
  void body() {
    /* INPUT */
    cin >> dotN >> phaseN; // [3, 500000], [3, 1000000]

    line.resize(phaseN);
    for (int phase = 0; phase < phaseN; phase++) {
      int start, end;
      cin >> start >> end;
      line[phase] = {start, end};
    }

    // init
    rank.resize(dotN, 1);
    parent.resize(dotN);
    for (int i = 0; i < dotN; i++)
      parent[i] = i;

    /** Union Find
     * Check if both of them is alreay unified.
     * If both are unified already, they are connected already.
     * So adding a new line between them consequently makes a cycle.
     * Stop at that phase; we made a cycle now.
     */
    int answer = 0;
    for (int i = 0; i < phaseN; i++) {
      if (Find(line[i].first) == Find(line[i].second)) {
        answer = i + 1;
        break;
      }

      Union(line[i].first, line[i].second);
    }

    /* OUTPUT */
    cout << answer;
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