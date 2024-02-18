// 240218 2 #14940
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct coord {
  int i, j;
  int distance;
};

class my {
  int width, length;
  vector<vector<int>> inputV, outputV;

  bool isValidCoordinate(int I, int J) {
    if (inputV[I][J] == 0)
      return false;
    if (outputV[I][J] != 0)
      return false;
    if (I < 0 || I >= length || J < 0 || J >= width)
      return false;
    if (I == target.i && J == target.j)
      return false;

    return true;
  }

  // check for 4 direction of starting point
  void add4CasesToQueue(queue<coord> &planedToVisit, int I, int J,
                        int distance) {
    // up
    if (isValidCoordinate(I - 1, J)) {
      planedToVisit.push({I - 1, J, distance});
    }
    // down
    if (isValidCoordinate(I + 1, J)) {
      planedToVisit.push({I + 1, J, distance});
    }
    // left
    if (isValidCoordinate(I, J - 1)) {
      planedToVisit.push({I, J - 1, distance});
    }
    // right
    if (isValidCoordinate(I, J + 1)) {
      planedToVisit.push({I, J + 1, distance});
    }
  }

public:
  coord target;

  void makeMap(const int &m, const int &n) {
    width = m;
    length = n;

    // input vector
    inputV = vector<vector<int>>(length, vector<int>(width));
    outputV = vector<vector<int>>(length, vector<int>(width, 0));
  }

  void input() {
    for (int i = 0; i < length; i++) {
      for (int j = 0; j < width; j++)
        cin >> inputV[i][j];
    }
  }

  void findTarget() {
    for (int i = 0; i < length; i++) {
      for (int j = 0; j < width; j++) {
        if (inputV[i][j] == 2) {
          target.i = i;
          target.j = j;
          target.distance = 0;
        }
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
    queue<coord> planedToVisit;
    // initiate the queue
    planedToVisit.push(target);

    while (!planedToVisit.empty()) {
      coord current = planedToVisit.front();
      planedToVisit.pop();

      add4CasesToQueue(planedToVisit, current.i, current.i, current.distance);

      outputV[current.i][current.j] = outputV[I][J] + 1;
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
  cin >> m >> n;
  my a;
  a.makeMap(m, n);
  a.input();
  a.findTarget();
  a.travelByBFS(a.target.i, a.target.j);
  a.output();
}