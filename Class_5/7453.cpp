// 240925 1 #7453
// Class 5
// 01:00
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
  vector<vector<int>> arr; //[ABCD][arrSize], [-,+2^28]

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
    for (int idx1 = 0; idx1 < arrSize; idx1++)
      for (int idx2 = 0; idx2 < arrSize; idx2++)
        AB.push_back(arr[0][idx1] + arr[1][idx2]);
    sort(AB.begin(), AB.end());
    // 1-2. CD : O(N^2)
    vector<int> CD = {};
    for (int idx1 = 0; idx1 < arrSize; idx1++)
      for (int idx2 = 0; idx2 < arrSize; idx2++)
        CD.push_back(arr[2][idx1] + arr[3][idx2]);
    sort(CD.begin(), CD.end());

    ll answerCnt = 0;

    // 2. use Two pointer, O(N^2) * N : = 64e12
    int idxL = 0, idxR = CD.size() - 1;
    while (idxL < AB.size() && idxR >= 0) {
      if (AB[idxL] == -CD[idxR]) {
        // count how many cases in there
        int cntAB = 1;
        for (int i = idxL + 1; i < AB.size(); i++) {
          if (AB[i] == AB[idxL]) {
            cntAB++;
            continue;
          }

          else {
            idxL = i; // update idxL
            break;
          }
          idxL = AB.size(); // update idxL
        }

        int cntCD = 1;
        for (int i = idxR - 1; i >= 0; i--) {
          if (CD[i] == CD[idxR]) {
            cntCD--;
            continue;
          }

          else {
            idxR = i; // update idxR
            break;
          }
          idxR = 0; // update idxR
        }

        answerCnt += cntAB * cntCD;
      }

      else if (AB[idxL] < -CD[idxR])
        idxL++;
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
