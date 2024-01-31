// 240131 4 #2164
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

void body() {
  // input
  int N;
  cin >> N;

  //  process
  // make a deck by STL queue;
  queue<int> deck;
  for (int i = 0; i < N; i++) {
    deck.push(i + 1);
  }

  while (N-- > 1) {
    // remove first card
    deck.pop();

    // add first card to the end of the deck
    deck.push(deck.front());
    deck.pop();
  }

  // output
  cout << deck.back();
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