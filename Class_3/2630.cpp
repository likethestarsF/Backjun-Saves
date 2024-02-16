// 240216 3 #2630
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class origami {
  int whiteCnt = 0;
  int blueCnt = 0;

  template <typename T> bool colorCheck(const T &paper) {
    const bool color = paper[0][0];
    for (const auto &elem : paper) {
      for (const auto &elem2 : elem)
        if (color != elem2) {
          return 1;
        }
    }
    return 0; // false when homogeneous
  }

public:
  vector<vector<bool>> initPaper;
  void input(const int &n) {
    initPaper = vector<vector<bool>>(n, vector<bool>(n)); // initPaper[i][j]

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        bool inp;
        cin >> inp;
        initPaper[i][j] = inp;
      }
    }
  }

  template <typename T>
  // only 2 Exits. 4 returns are made by 1 step.
  void DivideAndConquer(const T &paper, const int length) {
    // exit 1st : length is 1.
    if (length == 1) {
      if (paper[0][0] == 1)
        blueCnt++;
      else
        whiteCnt++;
    } else if (!colorCheck(paper)) {
      if (paper[0][0] == 1)
        blueCnt++;
      else
        whiteCnt++;
    }

    else {
      // DIVIDE into 4 papers: make the quarter paper
      for (int quarterIndex = 0; quarterIndex < 4; quarterIndex++) {
        vector<vector<bool>> quarter((length / 2), vector<bool>(length / 2));

        // DEF quarterIndex of paper
        int iDelta;
        int jDelta;
        if (quarterIndex == 0) {
          iDelta = 0;
          jDelta = 0;
        } else if (quarterIndex == 1) {
          iDelta = length / 2;
          jDelta = 0;
        } else if (quarterIndex == 2) {
          iDelta = 0;
          jDelta = length / 2;
        } else if (quarterIndex == 3) {
          iDelta = length / 2;
          jDelta = length / 2;
        } else {
          cerr << "error" << endl;
        }

        // copy paper to the quarter
        for (int i = 0; i < (length / 2); i++) {
          for (int j = 0; j < (length / 2); j++)
            quarter[i][j] = paper[i + iDelta][j + jDelta];
        }

        // Check if quarter is homogeoneous :false
        // recall and divide to quarter
        if (colorCheck(quarter)) {
          DivideAndConquer(quarter, length / 2);
        }

        // exit 2nd : quarter is homogeoneous.
        else {
          if (quarter[0][0] == 1)
            blueCnt++;
          else
            whiteCnt++;
        }
      }
    }
  }

  void output() { cout << whiteCnt << '\n' << blueCnt; }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  origami a;
  int n;
  cin >> n;

  a.input(n);
  a.DivideAndConquer(a.initPaper, n);
  a.output();
}