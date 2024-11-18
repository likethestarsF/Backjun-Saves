// 241118 1 #9935
// Class 4
// 00:40
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
// #define INF 1e8
// #define MAX 2147483647
// #define ll long long
using namespace std;

class MY {
  string input, explosive;
  vector<bool> isRemain;

  bool findExplosive(int idxInput) {
    // find explosive strings based on the isRemain
    int idxExplosive = 0;
    while (idxExplosive < explosive.length()) {
      if (idxInput >= input.length())
        return false;

      if (!isRemain[idxInput])
        idxInput++;

      else if (input[idxInput] == explosive[idxExplosive]) {
        idxInput++;
        idxExplosive++;
      }

      else
        return false;
    }

    return true;
  }

  void updateIsRemain(int cur) {
    int updated = 0;

    while (updated < explosive.length()) {
      if (isRemain[cur]) {
        isRemain[cur] = false;
        updated++;
      }
      cur++;
    }
  }

public:
  MY() {
    /* Input */
    cin >> input;     // [,1e6]
    cin >> explosive; // [,36]

    isRemain.resize(input.size(), true);
  }

  void body() {
    // find starting points
    const char key = explosive[0];
    vector<int> list = {};

    for (int i = 0; i < input.size(); i++) {
      if (input[i] == key)
        list.push_back(i);
    }

    // find explosives and update isRemain
    for (int cur = list.size() - 1; cur >= 0; cur--) {
      if (findExplosive(list[cur]))
        updateIsRemain(list[cur]);
    }

    /* Output */
    string result = "";
    for (int i = 0; i < input.size(); i++) {
      if (isRemain[i])
        result += input[i];
    }

    if (result == "")
      cout << "FRULA";
    else
      cout << result;
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  MY my;
  my.body();
}
