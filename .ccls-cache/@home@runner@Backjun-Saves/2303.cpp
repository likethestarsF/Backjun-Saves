// 240727 2 #2303
// Random Marthon 8 F
// 00:15
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {
  int playerMax;
  vector<vector<int>> cards;

public:
  void body() {
    cin >> playerMax;

    // #Input
    cards.resize(playerMax, vector<int>(5)); // cards[player][i]
    for (int player = 0; player < playerMax; player++) {
      for (int i = 0; i < 5; i++)
        cin >> cards[player][i];
    }

    int winner = 0;
    int maxScore = -1;
    for (int player = 0; player < playerMax; player++) {
      // Find each score
      int score = scoreCalculater(cards[player]);

      if (score >= maxScore) {
        winner = player;
        maxScore = score;
      }
    }

    cout << winner + 1;
  }

  int scoreCalculater(const vector<int> &cards) {
    int result = -1;

    const int size = cards.size();
    for (int i1 = 0; i1 < size; i1++) {
      for (int i2 = i1 + 1; i2 < size; i2++) {
        for (int i3 = i2 + 1; i3 < size; i3++) {
          int sum = cards[i1] + cards[i2] + cards[i3];
          if (sum % 10 > result)
            result = sum % 10;
        }
      }
    }

    return result;
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