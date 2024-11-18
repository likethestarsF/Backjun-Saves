// 241118 1 #9935
// Class 4
// 00:50
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

  void findExplosive(int idxInput) {
    vector<int> deleted = {};
    // find explosive strings based on the isRemain
    int idxExplosive = 0;
    while (idxExplosive < explosive.length()) {
      if (idxInput >= input.length())
        return;

      if (!isRemain[idxInput])
        idxInput++;

      else if (input[idxInput] == explosive[idxExplosive]) {
        // isRemain[indInput] = false;
        deleted.push_back(idxInput);

        idxInput++;
        idxExplosive++;
      }

      else
        return;
    }

    // update isRemain
    for (const int &target : deleted)
      isRemain[target] = false;
  }

public:
  MY() {
    /* Input */
    cin >> input;     // [,1e6]
    cin >> explosive; // [,36]

    isRemain.resize(input.size(), true);
  }

  void body() {

    // find explosives in the input and update isRemain
    for (int i = input.length() - 1; i >= 0; i--) {
      if (input[i] == explosive[0])
        findExplosive(i);
    }

    /* Output */
    int flag = true;
    for (int i = 0; i < input.length(); i++) {
      if (isRemain[i]) {
        cout << input[i];
        flag = false;
      }
    }

    if (flag)
      cout << "FRULA";
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
