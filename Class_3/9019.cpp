// 240311 2 #9019
// 240312 1 #9019
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
  int prev;
  char usedCommand;
};

class DSLR {
  int a, b;
  vector<node> visited;

  void quadCommand(queue<int> &checklist, const int &regi) {
    int toPush;

    // D
    toPush = D(regi);
    if (visited[toPush].usedCommand == 'X') {
      visited[toPush].prev = regi;
      visited[toPush].usedCommand = 'D';
      checklist.push(toPush);
    }
    // S
    toPush = S(regi);
    if (visited[toPush].usedCommand == 'X') {
      visited[toPush].prev = regi;
      visited[toPush].usedCommand = 'S';
      checklist.push(toPush);
    }
    // L
    toPush = L(regi);
    if (visited[toPush].usedCommand == 'X') {
      visited[toPush].prev = regi;
      visited[toPush].usedCommand = 'L';
      checklist.push(toPush);
    }
    // R
    toPush = R(regi);
    if (visited[toPush].usedCommand == 'X') {
      visited[toPush].prev = regi;
      visited[toPush].usedCommand = 'R';
      checklist.push(toPush);
    }
  }

  int D(int regi) {
    regi = regi * 2;
    if (regi > 9999) {
      regi %= 10000;
    }
    return regi;
  }

  int S(int regi) {
    if (regi == 0)
      regi = 9999;
    else
      regi--;
    return regi;
  }

  int L(int regi) {
    int d[4]; // 3 2 1 0 -> 2 1 0 3
    for (int i = 0; i < 4; i++) {
      d[i] = regi % 10;
      regi /= 10;
    }

    return (d[2] * 1000 + d[1] * 100 + d[0] * 10 + d[3]);
  }

  int R(int regi) {
    int d[4]; // 3 2 1 0 -> 0 3 2 1
    for (int i = 0; i < 4; i++) {
      d[i] = regi % 10;
      regi /= 10;
    }

    return (d[0] * 1000 + d[3] * 100 + d[2] * 10 + d[1]);
  }

public:
  DSLR(int A, int B) {
    node initNode;
    initNode.prev = -1;
    initNode.usedCommand = 'X';
    visited.resize(10000, initNode);
    a = A;
    b = B;
  }

  // Worst case. O(4^n)..?
  void BFS() {
    queue<int> checklist;
    quadCommand(checklist, a); // init the queue

    while (!checklist.empty()) {
      int cur = checklist.front();
      checklist.pop();

      // REACH THE END : IT IS ONE AND ONLY theoretically
      // -> need to backtracking visited vectors to find every cmd used till now
      if (cur == b) {
        return;
      }

      // NOT REACH THE END
      // add elems to checklist. 4 elems at most
      quadCommand(checklist, cur);
    }

    cerr << "cannot reach the answer";
  }

  string cmdstring() {
    node curNode = visited[b]; // init the node for backtracking
    string result = {};

    if (curNode.usedCommand == 'X') {
      cerr << "error in BFS" << endl;
      return "X";
    }

    // break when we reach the a
    while (true) {
      // save cmds in result; output will be reversed
      result += curNode.usedCommand;

      // ONE AND ONLY EXIT: curNode is right after a
      if (curNode.prev == a)
        return result;

      // goto next node
      curNode = visited[curNode.prev];
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

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    DSLR atob(a, b);

    atob.BFS();
    string output = atob.cmdstring();
    reverse(output.begin(), output.end());
    cout << output << '\n';
  }
}