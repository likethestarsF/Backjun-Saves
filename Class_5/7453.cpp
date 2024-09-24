// 240925 1 #7453
// Class 5
// 00:20
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 2147483647
#define ll long long
using namespace std;

class MY {
  int arrSize;             // [,400]
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
    // FIND arr[0][a] + arr[1][b] = arr[2][c] + arr[3][d] == 0
    int answerCnt = 0;
    for (int i = 0; i < 4; i++)
      sort(arr[i].begin(), arr[i].end());

    // 1. Select 1st elem, O(N)
    for (int idx1 = 0; idx1 < arrSize; idx1++) {
      const int *first = &arr[0][idx1];

      // 2. Select 2nd elem, O(N) : O(N^2) : 400^2 = 16e4
      for (int idx2 = 0; idx2 < arrSize; idx2++) {
        const int *second = &arr[1][idx2];

        // 3. Select 3rd and 4th by Two pointer, O(N + N) : O(N^3) : 64e6
        const int sumPartial = *first + *second;
        int idx3 = 0, idx4 = arrSize - 1;
        while (idx3 < arrSize && idx4 >= 0) {
          const int *third = &arr[2][idx3];
          const int *forth = &arr[3][idx4];
          int sum = sumPartial + *third + *forth;

          if (sum == 0) {
            answerCnt++;
            idx3++;
            idx4--;
          }

          else if (sum < 0)
            idx3++;
          else if (sum > 0)
            idx4--;
        }
      }
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
