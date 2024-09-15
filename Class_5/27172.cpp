// 240915 1 #27172
// Class 5
// 00:15
#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 1000000
using namespace std;

class my {
  int playerN;
  vector<int> card;
  vector<int> score;

  void Battle(const int &p1, const int &p2) {
    if (card[p1] % card[p2] == 0) {
      score[p1]--;
      score[p2]++;
    }

    else if (card[p2] % card[p1] == 0) {
      score[p2]--;
      score[p1]++;
    }
  }

public:
  void body() {
    /* INPUT */
    cin >> playerN;
    card.resize(playerN);
    for (int i = 0; i < playerN; i++)
      cin >> card[i]; // [1, 1000000]

    /** Game RULES
     * 1. if x % y == 0, y wins, x loses.
     * 2. else, both x and y draw.
     * 3. winner gets 1 point, loser loses 1 point. nothig changes if draw.
     * a player must battle with everyone else; each battle happen only 1 time.
     */
    score.resize(playerN, 0);
    for (int p1 = 0; p1 < playerN; p1++)
      for (int p2 = p1 + 1; p2 < playerN; p2++) {
        Battle(p1, p2);
      }

    /* OUTPUT */
    for (const int &e : score)
      cout << e << " ";
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