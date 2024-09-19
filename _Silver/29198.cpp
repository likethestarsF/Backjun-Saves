// 240919 1 #29198
// Random Marathon 16 H
// 00:15
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {
  int strN, length, selecN;
  vector<string> str;

  template <typename T> void test(T k, bool flag) {
    // test
    for (auto e : k)
      clog << e << endl;
    if (flag)
      exit(1);
  }

public:
  void body() {
    /* Input */
    cin >> strN >> length >> selecN;

    str.resize(strN);
    for (int i = 0; i < strN; i++) {
      cin >> str[i];
      sort(str[i].begin(), str[i].end());
    }
    sort(str.begin(), str.end());

    /* Main */
    vector<int> alphabetCnt(26, 0);
    for (int i = 0; i < selecN; i++)
      for (int c = 0; c < str[i].size(); c++) {
        alphabetCnt[str[i][c] - 'A']++;
      }

    /* Output */
    for (int i = 0; i < alphabetCnt.size(); i++) {
      while (alphabetCnt[i]--) {
        cout << (char)(i + 'A');
      }
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
