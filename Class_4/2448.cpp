// 241003 1 #2448
// Class 4
// 01:20
#include <algorithm>
#include <iostream>
#include <vector>
// #define MAX 2147483647
// #define ll long long
using namespace std;

class MY {
  vector<string> line;
  vector<int> starNum;

  inline string oneStar() { return "  *   "; }
  inline string twoStar() { return " * *  "; }
  inline string fiveStar() { return "***** "; }
  inline void endl() { cout << '\n'; }
  inline string blank(const int &k) {
    if (k < 0)
      return "";
    string result(k, ' ');
    return result;
  }

public:
  // MY() {}

  void body() {
    /* Input */
    int n;
    cin >> n; // 3*2^k
    line.resize(n, "");
    starNum.resize(n, 0);
    /**
     * 1. First indentation : based on the 'i' of line
     * * 3 lines form a group, use (i/3)*3
     * 2.ith = 2 * (idx(=0)++th),  except i = 0~2.
     * * 3 = [0] * 2, 4 = [1] * 2, 6 = [0] * 2
     * 3. Use starNum to save the number of stars.
     * * (i~i+2)th lines have the number of (i/3) + 1 block: star or non-star
     * * Add indentation between idxs, using starNum.
     * * after adding indentaion, update starNum since non-star block is added.
     */

    for (int up = 3; up <= n; up *= 2) {
      // first init; first loop has no previous data
      if (up == 3) {
        line[0] = oneStar();
        line[1] = twoStar();
        line[2] = fiveStar();

        for (int i = 0; i < 3; i++) {
          starNum[i]++;

          cout << blank(n - 3);
          cout << line[i];
          cout << blank(n - 3);
          endl();
        }

        continue; // pass the below loop
      }

      int idx = 0;
      for (int down = up / 2; down < up; down++) {

        // 3.
        starNum[down] = starNum[idx] * 2;
        const int remainStarNum = 1 + (down / 3) - starNum[down];
        line[down] = line[idx] + blank(6 * remainStarNum) + line[idx];
        starNum[down] += remainStarNum;

        // Printing a line
        cout << blank(n - 3 - (down / 3) * 3);
        cout << line[down];
        cout << blank(n - 3 - (down / 3) * 3);
        endl();
        idx++;
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
  // std::clog.setstate(std::ios_base::failbit);

  MY my;
  my.body();
}
