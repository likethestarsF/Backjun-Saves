// 240301 2 #7569
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct coord {
  short h, l, w;
};

class my {
  short width, length, heigth;
  vector<vector<vector<int>>> tomato;
  vector<vector<vector<bool>>> tomatoVisit;
  queue<coord> list; // push unripe tomato (turn it to ripe)

public:
  int dayCnt = 0;
  void input() { cin >> width >> length >> heigth; }
  void input2() {
    tomato.resize(heigth, vector<vector<int>>(length, vector<int>(width)));
    tomatoVisit.resize(
        heigth, vector<vector<bool>>(length, vector<bool>(width, false)));
    for (int h = 0; h < heigth; h++) {
      for (int l = 0; l < length; l++) {
        for (int w = 0; w < width; w++) {
          cin >> tomato[h][l][w];
        }
      }
    }
  }

  // for initialize
  void findMature() {
    for (int h = 0; h < heigth; h++) {
      for (int l = 0; l < length; l++) {
        for (int w = 0; w < width; w++) {
          if (tomato[h][l][w] == 1) {
            listPush(h, l, w); // 6 direction push
            tomatoVisit[h][l][w] = true;
          }
        }
      }
    }
  }

  void listPush(short h, short l, short w) {
    short dH[6] = {1, -1, 0, 0, 0, 0};
    short dL[6] = {0, 0, 1, -1, 0, 0};
    short dW[6] = {0, 0, 0, 0, 1, -1};

    for (int i = 0; i < 6; i++) {
      short newH = h + dH[i];
      short newL = l + dL[i];
      short newW = w + dW[i];
      // boundary Check
      if (newH >= 0 && newL >= 0 && newW >= 0 && newH < heigth &&
          newL < length && newW < width) {
        // is it visited?
        if (tomatoVisit[newH][newL][newW] == false) {
          // is it unripe?
          if (tomato[newH][newL][newW] == 0) {
            list.push({newH, newL, newW});
            tomatoVisit[newH][newL][newW] = true;
          }
        }
      }
    }
  }

  void BFS() {
    while (list.size() > 0) {
      int size = list.size();
      while (size--) { // pop every existed elems
        clog << "size : " << size << " list elem : " << list.size() << endl;
        coord current = list.front();
        list.pop();
        tomato[current.h][current.l][current.w] = 1; // update 3D vector
        listPush(current.h, current.l, current.w);
      }

      dayCnt++;
    }
  }

  void ripeCheck() {
    for (int h = 0; h < heigth; h++) {
      for (int l = 0; l < length; l++) {
        for (int w = 0; w < width; w++) {
          if (tomato[h][l][w] == 0) {
            dayCnt = -1;
            break;
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
  std::clog.setstate(std::ios_base::failbit);

  my a;
  a.input();
  a.input2();
  a.findMature();
  a.BFS();
  a.ripeCheck();
  cout << a.dayCnt;
}