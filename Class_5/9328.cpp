// 241219 1 #9328
// Class 5
// 01:30
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
// #define INF 1e8
// #define MAX 2147483647
// #define ll long long
using namespace std;

class MY {
  struct coord {
    int height, width;
    char key;
    bool isOpened = false;
  };

  int docs = 0;
  vector<bool> keyList;
  int height, width;
  vector<vector<char>> map;
  vector<vector<bool>> isVisited;

  vector<coord> doors = {};

  void initiateHeist() {
    // 1. bottom
    for (int i = 0; i < width; i++)
      checkTheSpot(0, i);

    // 2. left, right sides
    for (int i = 0; i < height; i++) {
      checkTheSpot(i, 0);
      checkTheSpot(i, width - 1);
    }

    // 3. top
    for (int i = 0; i < width; i++)
      checkTheSpot(height - 1, i);

    // 4. blocked lists?
    openTheDoors();
  }

  void checkTheSpot(const int &height, const int &width) {
    if (isVisited[height][width])
      return;

    if (map[height][width] == '*') {
      isVisited[height][width] = true;
    }

    else if (map[height][width] == '$') {
      isVisited[height][width] = true;
      docs++;
      // add to the startpoint
      checkAround(height, width);
    }

    else if (map[height][width] == '.') {
      isVisited[height][width] = true;
      // add to the startpoint
      checkAround(height, width);
    }

    else if (map[height][width] >= 'A' && map[height][width] <= 'Z') {
      // have a key for the door
      if (keyList[map[height][width] - 'A']) {
        isVisited[height][width] = true;
        // add to the startpoint
        checkAround(height, width);
      }

      else {
        // add to the blocked list
        doors.push_back({height, width, (char)(map[height][width] + 32)});
      }
    }

    // get the key
    else if (map[height][width] >= 'a' && map[height][width] <= 'z') {
      isVisited[height][width] = true;

      keyList[map[height][width] - 'a'] = true;
      // add to the startpoints
      checkAround(height, width);
      // recheck the blocked doors
      openTheDoors();
    }

    else
      exit(1);
  }

  void checkAround(const int &hStart, const int &wStart) {
    const int dH[] = {0, 0, 1, -1}, dW[] = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++) {
      const int nextH = hStart + dH[i];
      const int nextW = wStart + dW[i];
      // 1. boundary
      if (nextH < 0 || nextH >= height || nextW < 0 || nextW >= width)
        continue;
      // 2. isVisited
      if (isVisited[nextH][nextW])
        continue;

      checkTheSpot(nextH, nextW);
    }
  }

  void openTheDoors() {
    const int curSize = doors.size();
    for (int i = 0; i < curSize; i++) {
      if (doors[i].isOpened)
        continue;

      if (keyList[(doors[i].key - 'a')]) {
        doors[i].isOpened = true;
        isVisited[doors[i].height][doors[i].width] = true;
        checkAround(doors[i].height, doors[i].width);
      }
    }
  }

public:
  MY() {
    keyList.resize('z' - 'a' + 1, false);
    cin >> height >> width; // [2, 100] -> 1e4
    map.resize(height, vector<char>(width));
    isVisited.resize(height, vector<bool>(width, false));
  }

  void body() {
    /* Input */
    for (int h = 0; h < height; h++)
      for (int w = 0; w < width; w++)
        cin >> map[h][w];

    string keys;
    cin >> keys;
    if (keys != "0")
      for (const char &c : keys)
        keyList[c - 'a'] = true;

    /* Process */
    // travel from the entrance
    // don't need to revisit the same place?
    // unless the door is closed.
    // If key is updated, recheck the every doors I fail to enter
    // 1. Outer borderlines

    // check the walls
    initiateHeist();

    /* Output */
    cout << docs << '\n'; // Max $
    for (const auto &c : isVisited) {

      for (auto d : c)
        cout << d;
      cout << endl;
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

  int cases;
  cin >> cases;
  while (cases--) {
    MY my;
    my.body();
  }
}
