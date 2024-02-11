// 240211 3 #1620
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void body() {
  // input
  int n, m;
  cin >> n >> m;

  map<string, int> pokemonByName;
  map<int, string> pokemonByNumber;
  // loop for input
  for (int i = 0; i < n; i++) {
    string name;
    cin >> name;
    pokemonByName.insert({name, i + 1});
    pokemonByNumber.insert({i + 1, name});
  }

  // loop for quiz
  while (m--) {
    string q;
    cin >> q;
    // answer the name by pokemonByNumber
    if (q[0] < 58)
      cout << pokemonByNumber[stoi(q)] << '\n';
    // answer the number
    else
      cout << pokemonByName[q] << '\n';
  }
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