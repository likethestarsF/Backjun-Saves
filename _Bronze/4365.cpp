// 240802 3 #4365
// 240803 1 #4365
// Random Marthon 9 D
// 00:35
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class my {
  int nMax;
  vector<vector<int>> shuffles = {}; // index 0 isn't used
  vector<string> indexOfNames = {"2", "3",  "4",    "5",     "6",    "7",  "8",
                                 "9", "10", "Jack", "Queen", "King", "Ace"};
  vector<string> indexOfSuits = {"Clubs", "Diamonds", "Hearts", "Spades"};

  vector<int> deck = {}; // index 0 isn't used
  void initializeDeck() {
    deck.resize(53);
    for (int i = 0; i <= 52; i++)
      deck[i] = i;
  }

  // swap is more complcated with little optimization. just copy.
  void doShuffle(int n) {
    vector<int> tempDeck;
    tempDeck.resize(53, 0);
    for (int i = 1; i <= 52; i++) {
      tempDeck[i] = deck[shuffles[n][i]];
    }
    deck = tempDeck;
  }

  void printCurrentDeck() {
    for (int i = 1; i <= 52; i++) {
      cout << indexOfNames[(deck[i] - 1) % 13] << " of ";
      cout << indexOfSuits[(deck[i] - 1) / 13] << '\n';
    }
    cout << '\n';
  }

public:
  void body() {
    // # Input
    cin >> nMax; // [1,100]
    shuffles.resize(nMax, vector<int>(52 + 1));

    for (int i_forN = 0; i_forN < nMax; i_forN++) {
      for (int i = 1; i <= 52; i++) { // 0 is not used
        cin >> shuffles[i_forN][i];
      }
    }

    // # Main Process
    initializeDeck();
    while (true) {
      int n;
      cin >> n;

      if (cin.eof())
        break; // Break when reaches EOF

      doShuffle(n - 1);
      printCurrentDeck();
    }

    // output
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