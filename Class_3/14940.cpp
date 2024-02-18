// 240218 2 #14940
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct coord {
  int i, j;
};

class my {
  int width, length;
  vector<vector<bool>> visited;
  vector<vector<int>> outputV;

  bool isValidCoordinate(const int &I, const int &J) {
    if (I < 0 || I >= length || J < 0 || J >= width) // boundary check goes 1st
      return false;
    if (visited[I][J] == true)
      return false;

    return true;
  }

  // check for 4 direction of starting point
  void add4CasesToQueueAndUpdate(queue<coord> &planedToVisit, const int &I,
                                 const int &J, const int &prevDistance) {
    // up
    if (isValidCoordinate(I - 1, J)) {
      planedToVisit.push({I - 1, J});
      outputV[I - 1][J] = prevDistance + 1;
      visited[I - 1][J] = true;
    }
    // down
    if (isValidCoordinate(I + 1, J)) {
      planedToVisit.push({I + 1, J});
      outputV[I + 1][J] = prevDistance + 1;
      visited[I + 1][J] = true;
    }
    // left
    if (isValidCoordinate(I, J - 1)) {
      planedToVisit.push({I, J - 1});
      outputV[I][J - 1] = prevDistance + 1;
      visited[I][J - 1] = true;
    }
    // right
    if (isValidCoordinate(I, J + 1)) {
      planedToVisit.push({I, J + 1});
      outputV[I][J + 1] = prevDistance + 1;
      visited[I][J + 1] = true;
    }
  }

public:
  coord target;

  void makeMap(const int &m, const int &n) {
    width = m;
    length = n;

    // vector initialization
    visited = vector<vector<bool>>(length, vector<bool>(width, false));
    outputV = vector<vector<int>>(length, vector<int>(width, false));
  }

  void input() {
    for (int i = 0; i < length; i++) {
      for (int j = 0; j < width; j++) {
        int inp;
        cin >> inp;

        if (inp == 1)
          inp = -1;
        else if (inp == 0)
          visited[i][j] = true;
        else if (inp == 2) { // find a target
          target = {i, j};
          visited[i][j] = true;
          inp = 0;
        }

        outputV[i][j] = inp;
      }
    }
  }

  /* use BFS by queue - one steps equal to the 1 distance.
  ** start from the target
  ** add 4-d to queue fit inCOND.
  : COND. it is not 0, not visited, not out of bound map,
  + not the target point; starting point so outputV is 0. can be cause error
  + overwriting starting point at the end of BFS also seems viable.
  ** change the position value to that of prev position + 1
  */
  void travelByBFS() {
    // initiate the queue
    queue<coord> planedToVisit = {};
    planedToVisit.push(target);

    // select -> (COND check) -> call a new one(coord)
    while (!planedToVisit.empty()) {
      coord current = planedToVisit.front();
      planedToVisit.pop();

      add4CasesToQueueAndUpdate(planedToVisit, current.i, current.j,
                                outputV[current.i][current.j]);
    }
  }

  void output() {
    for (int i = 0; i < length; i++) {
      for (int j = 0; j < width; j++) {
        cout << outputV[i][j] << ' ';
      }
      cout << '\n';
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

  int m, n;
  cin >> n >> m;
  my a;
  a.makeMap(m, n);
  a.input();
  a.travelByBFS();
  a.output();
}