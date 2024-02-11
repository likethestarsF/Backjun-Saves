// 240211 4 #1764
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

void body() {
  // input
  int n, m;
  cin >> n >> m;

  // never seen
  set<string> neverSeen;
  while (n--) {
    string str;
    cin >> str;
    neverSeen.insert(str);
  }

  // never seen and heard
  set<string> neverSeenAndHeard;
  while (m--) {
    string str;
    cin >> str;
    if (neverSeen.find(str) != neverSeen.end())
      neverSeenAndHeard.insert(str);
  }

  // output
  cout << neverSeenAndHeard.size() << '\n';
  for (const auto &elem : neverSeenAndHeard)
    cout << elem << '\n';
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