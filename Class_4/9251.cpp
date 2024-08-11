// 240811 4 #9251
// Class 4
// 00:30
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {
  string str1, str2;

  int FindLCS() {
    vector<vector<int>> LCS(str1.length(), vector<int>(str2.length(), 0));

    // (0, 0)
    if (str1[0] == str2[0])
      LCS[0][0] = 1;

    // row = 0
    for (int col = 1; col < str2.length(); col++)
      if (str1[0] == str2[col])
        LCS[0][col] = 1;
      else
        LCS[0][col] = LCS[0][col - 1];

    // col = 0
    for (int row = 1; row < str1.length(); row++)
      if (str1[row] == str2[0])
        LCS[row][0] = 1;
      else
        LCS[row][0] = LCS[row - 1][0];

    // general cases
    for (int row = 1; row < str1.length(); row++) {
      for (int col = 1; col < str2.length(); col++) {
        if (str1[row] == str2[col])
          LCS[row][col] = LCS[row - 1][col - 1] + 1;
        else
          LCS[row][col] = max(LCS[row - 1][col], LCS[row][col - 1]);
      }
    }

    // findMax
    int result = 0;
    for (int row = 0; row < str1.length(); row++)
      for (int col = 0; col < str2.length(); col++)
        if (result < LCS[row][col])
          result = LCS[row][col];
    return result;
  }

public:
  void body() {
    cin >> str1 >> str2; // [1, 1000] Captial Alphabet.

    cout << FindLCS();
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