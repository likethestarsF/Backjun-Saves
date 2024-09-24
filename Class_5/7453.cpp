// 240925 1 #7453
// Class 5
// 01:30
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 2147483647
#define ll long long
using namespace std;

class MY {
  int arrSize;             // [,4000]
  vector<vector<int>> arr; // [ABCD][arrSize], [-,+2^28]

public:
  MY() {
    /* Input */
    cin >> arrSize;
    arr.resize(4, vector<int>(arrSize));
    for (int i = 0; i < arrSize; i++)
      for (int j = 0; j < 4; j++)
        cin >> arr[j][i];
  }

  void body() {
    /** FIND arr[0][a] + arr[1][b] = arr[2][c] + arr[3][d] == 0
     * 1. Divide 4 arr into 2 & 2 : sum(AB) & sum(CD)
     * 2. Find AB + CD == 0 , AB == -CD
     */

    // 1-1. sum(AB) : O(N^2)
    vector<int> AB = {};
    AB.reserve(arrSize * arrSize);
    for (int idx1 = 0; idx1 < arrSize; idx1++)
      for (int idx2 = 0; idx2 < arrSize; idx2++)
        AB.push_back(arr[0][idx1] + arr[1][idx2]);
    sort(AB.begin(), AB.end());
    // 1-2. CD : O(N^2)
    vector<int> CD = {};
    CD.reserve(arrSize * arrSize);
    for (int idx1 = 0; idx1 < arrSize; idx1++)
      for (int idx2 = 0; idx2 < arrSize; idx2++)
        CD.push_back(arr[2][idx1] + arr[3][idx2]);
    sort(CD.begin(), CD.end());

    ll answerCnt = 0;

    // 2. Two pointer
    int idxL = 0, idxR = arrSize * arrSize - 1;
    while (idxL < arrSize * arrSize && idxR >= 0) {
      // 2-1.
      if (AB[idxL] == -CD[idxR]) {
        ll cntAB = 1;
        while (idxL + 1 < arrSize * arrSize && AB[idxL] == AB[idxL + 1])
          idxL++, cntAB++;

        ll cntCD = 1;
        while (idxR - 1 >= 0 && CD[idxR] == CD[idxR - 1])
          idxR--, cntCD++;

        answerCnt += cntAB * cntCD;
        idxL++;
      }
      // 2-2.
      else if (AB[idxL] < -CD[idxR])
        idxL++;
      // 2-3.
      else if (AB[idxL] > -CD[idxR])
        idxR--;
    }

    cout << answerCnt;
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
