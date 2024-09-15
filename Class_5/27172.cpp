// 240915 1 #27172
// Class 5
// 00:40
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define MAX 1000000
using namespace std;

class my {
  int playerN;
  vector<bool> card;
  vector<int> player;
  vector<int> score;

public:
  void body() {
    card.resize(MAX + 1, false);
    score.resize(MAX + 1, 0);
    /* INPUT */
    cin >> playerN;
    player.resize(playerN);
    for (int i = 0; i < playerN; i++) {
      cin >> player[i]; // [1, 1000000]
      card[player[i]] = true;
    }

    /** Game RULES
     * 1. if x % y == 0, y wins, x loses.
     * 2. else, both x and y draw.
     * 3. winner gets 1 point, loser loses 1 point. nothig changes if draw.
     * a player must battle with everyone else; each battle happen only 1 time.


     * Use Sieve of Eratosthenes
     */
    for (int p1 = 0; p1 < playerN; p1++)
      for (int num = player[p1] * 2; num <= MAX; num += player[p1]) {
        if (card[num]) {
          // Battle when num is a one of the cards
          score[player[p1]]++;
          score[num]--;
        }
      }

    /* OUTPUT */
    for (int i = 0; i < playerN; i++) {
      cout << score[player[i]] << " ";
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