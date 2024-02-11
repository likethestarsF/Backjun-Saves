// 240210 6 #18111
// 240211 1 #18111
/* Basically, placing takes less time.
** flattening process starts from reducing the gap between max and min.
** bottom up style will be applyed 'cause placing takes less time.
** First, see if it is possible to place the block at min level.
** If possible, then place it. Else, goto breaking the max level by 1.
** Second Check again minLevel and maxLevel are same.
** If not, Do the loop again. Until reach the point written above.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class minecraft {
  int width, length, block; // (w,l) : (i,j)
  int plane;
  int blockNeeded = 0;

public:
  vector<int> ground;
  int maxLevel, minLevel;

  int cntPlaced = 0;  // 1s
  int cntBreaked = 0; // 2s

  minecraft() {
    // input
    cin >> width >> length >> block;
    plane = width * length;

    for (int i = 0; i < width; i++) {    // w
      for (int j = 0; j < length; j++) { // l
        int initLevel;
        cin >> initLevel;
        ground.push_back(initLevel);
      }
    }

    sort(ground.begin(), ground.end());

    maxLevel = ground.back();
    minLevel = ground.front();
  }

  /* Description for placeBlockCheck.
  ** DEF. needToPlace: X, totalBlock of a floor: N = width * length
  ** COND to place:
  ** 1. X <= B
  ** 2. X < 2*(N-X) : 3X < 2N
  */
  void placeBlockCheck() {
    blockNeeded = 0;
    // loop for count blocks
    for (const auto &elem : ground) {
      if (elem == minLevel) {
        blockNeeded++;
      } else
        break; // task are finished.
    }

    // check if placing can be done.
    if (/* COND 1 */ blockNeeded <= block &&
        /* COND 2 */ 3 * blockNeeded < 2 * plane)
      placeBlock();
    else
      breakBlock();
  }

  void placeBlock() {
    for (auto &elem : ground) {
      if (elem == minLevel) {
        elem++;
        cntPlaced++;
        block--;
      } else
        break;
    }
    minLevel = ground.front();
  }

  // breaking blocks at max level.
  void breakBlock() {
    for (int i = ground.size() - 1;; i--) {
      if (ground[i] == maxLevel) {
        ground[i]--;
        cntBreaked++;
        block--;
      } else
        break;
    }
    maxLevel = ground.back();
  }
};

void body() {
  minecraft steve;

  while (true) {
    if (steve.minLevel == steve.maxLevel) // flattening finished
      break;
    steve.placeBlockCheck();
  }

  // output
  int time = steve.cntPlaced + steve.cntBreaked * 2;
  cout << time << ' ' << steve.ground.front();
}

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  body();
}