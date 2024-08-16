// 240816 2 #11195
// Random Marathon 11 B
// 00:10
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {
  vector<int> table;

public:
  void body() {
    string input;
    cin >> input; // len = [1, 1000], [a,z]

    // parsing
    table.resize(26 /* a to z */, 0);
    for (const char &c : input)
      table[c - 'a']++;

    int answer = 0;
    bool isAllEven = true;
    for (int i = 0; i < table.size(); i++) {
      if (table[i] % 2 == 0)
        continue;

      else {
        if (isAllEven)
          isAllEven = false;
        else
          answer++; // remv 1 elem
      }
    }

    cout << answer;
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