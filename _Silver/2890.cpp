// 240808 3 #2890
// Random Marathon 10 E
// 00:30
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {
  int rowSize, colSize;
  vector<int> player;

public:
  void body() {
    // input
    cin >> rowSize >> colSize;
    player.resize(10, -1); // [0] is not used.

    for (int row = 0; row < rowSize; row++) {
      string row_str;
      cin >> row_str;

      for (int col = 0; col < colSize; col++) {
        if (row_str[col] == '.' || row_str[col] == 'S' || row_str[col] == 'F')
          continue;
        else {
          // player[i] with a small value is low rank
          player[(row_str[col]) - '0'] = col;
          break;
        }
      }
    }

    // find the rank of players
    vector<int> ranks;
    ranks.resize(10, 0);
    int rank = 1, prev = 100;

    vector<int> player_sorted = player;
    sort(player_sorted.begin(), player_sorted.end(), greater<int>());
    for (int i = 0; i < 9; i++) {
      if (prev != player_sorted[i]) {
        ranks[rank] = player_sorted[i];
        rank++;
      }

      prev = player_sorted[i];
    }

    // output
    for (int i = 1; i < 10; i++) {
      for (int j = 1; j < 10; j++) {
        if (player[i] == ranks[j]) {
          cout << j << '\n';
          break;
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
  // std::clog.setstate(std::ios_base::failbit);

  my a;
  a.body();
}