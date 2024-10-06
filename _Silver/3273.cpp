// 241006 1 #3273
// Random Marathon 18 G
// 00:20
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
// #define INF 1e8
// #define MAX 2147483647
// #define ll long long
using namespace std;

class MY {
  int n;
  vector<int> list;
  int target;
  int cnt = 0;

public:
  MY() {}

  void body() {
    /* Input */
    cin >> n; // [,1e5]
    list.resize(n);
    for (int i = 0; i < n; i++)
      cin >> list[i]; // [,1e7]
    sort(list.begin(), list.end());
    cin >> target; // [,2e7]

    int ptrL = 0, ptrR = n - 1;
    while (ptrL < ptrR && ptrL < n - 1) {
      int sum = list[ptrL] + list[ptrR];

      while (sum > target && ptrL < ptrR - 1) {
        ptrR--;
        sum = list[ptrL] + list[ptrR];
      }

      if (sum == target)
        cnt++;

      ptrL++;
    }

    cout << cnt;
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
