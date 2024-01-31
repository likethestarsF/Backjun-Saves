// 240131 4 #2164
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void body() {
  // input
  int N;
  cin >> N;

  //  process
  // make a deck by vector;
  vector<int> deck(N);
  for (int i = 0; i < N; i++) {
    deck[i] = i + 1;
  }

  while (N-- > 1) {
    // remove the first card
    deck.erase(deck.begin());
    // move the first card to last
    deck.push_back(*deck.begin());
    deck.erase(deck.begin());
  }

  // output
  cout << deck[0];
}

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  body();
}