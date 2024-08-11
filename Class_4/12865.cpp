// 240811 5 #12865
// Class 4
// 01:00
#include <algorithm>
#include <iostream>
#include <vector>

struct item {
  int weight, value;
};

using namespace std;
class my {
  int itemN, weightMax;
  vector<item> list;

  int FindMax() {
    // DP[ith][occupied_weight] = Value;
    vector<vector<int>> DP(itemN + 1, vector<int>(weightMax + 1, 0));

    for (int idxItem = 1; idxItem <= itemN; idxItem++) {
      for (int w = 0; w <= weightMax; w++) {
        // 2. ith can't be selected
        DP[idxItem][w] = DP[idxItem - 1][w];

        // 1. ith can be selected; already selected or not
        // SELECTED: DP[i][w] = DP[i-1][w + list[i].weight] + list[i].value;
        if (w >= list[idxItem].weight)
          DP[idxItem][w] =
              max(DP[idxItem][w], DP[idxItem - 1][w - list[idxItem].weight] +
                                      list[idxItem].value);
      }
    }

    int max = 0;
    for (int w = 0; w <= weightMax; w++)
      max = std::max(DP[itemN][w], max);

    return max;
  }

public:
  void body() {
    // input
    cin >> itemN >> weightMax; // [1, 100], [1, 100000]
    list.resize(itemN + 1);
    for (int i = 1; i <= itemN; i++)
      cin >> list[i].weight >> list[i].value; // [1, 100000], [0, 1000]

    cout << FindMax();
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