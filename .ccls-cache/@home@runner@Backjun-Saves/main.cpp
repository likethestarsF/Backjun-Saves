// 240216 3 #2630
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class origami {
  int whiteCnt = 0;
  int blueCnt = 0;

  template <typename T> int colorCheck(const T &paper) {
    const int color = paper[0][0];
    for (const auto elem : paper) {
      for (const auto elem2 : elem)
        if (color != elem2) {
          return -1;
        }
    }
    return color;
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
  void DivideAndConquer(const T &paper, int length) {
    // exit 1st : length is 1.
    if (length == 1) {
      if (paper[0][0] == 1)
        blueCnt++;
      else
        whiteCnt++;
      return; // exit because length is 1
    }

    // DIVIDE into 4 papers: make the quarter paper
    for (int init = 1; init <= 4; init++) {
      vector<vector<bool>> quarter(length / 2, vector<bool>(length / 2));

      // DEF init point of paper
      int iDelta;
      int jDelta;
      switch (init) {
      case 1:
        iDelta = 0;
        jDelta = length / 2;
        break;
      case 2:
        iDelta = 0;
        jDelta = 0;
      case 3:
        iDelta = length / 2;
        jDelta = 0;
        break;
      case 4:
        iDelta = length / 2;
        jDelta = length / 2;
      default:
        cerr << "error" << endl;
        break;
      }

      // copy paper to the quarter
      for (int i = 0; i < length / 2; i++) {
        for (int j = 0; j < length / 2; j++)
          quarter[i][j] = paper[i + iDelta][j + jDelta];
      }

      // Check if quarter is homogeoneous: -1:non-homo, 0:W, 1:B
      int color = colorCheck(quarter);
      // exit 2nd : quarter is homogeoneous.
      if (color != -1) {
        if (color == 1)
          blueCnt++;
        else
          whiteCnt++;
        return; // exit :DivideAndConquer
      }

      // else recall and divide to quarter
      else {
        DivideAndConquer(quarter, length / 2);
      }
    }
  }

  void output() { cout << whiteCnt << '\n' << blueCnt << '\n'; }

  void test_input() {
    cout << endl << endl;
    for (const auto &elem : initPaper) {
      for (int i = 0; i < initPaper.size(); i++)
        cout << elem[i] << ' ';
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

  origami a;
  int n;
  cin >> n;

  a.input(n);
  a.test_input();
  // a.DivideAndConquer(a.initPaper, n);
  // a.output();
}