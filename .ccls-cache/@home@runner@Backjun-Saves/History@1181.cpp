// 240131 2 #1181
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void body() {
  // input
  int n;
  vector<string> v;

  cin >> n;

  for (int i = 0; i < n; i++) {
    string temp;
    bool flag = true;
    cin >> temp;

    // remove duplicate elem.
    for (const auto &s : v) {
      if (temp == s) {
        flag = 0;
        break;
      }
    }

    // push back v.
    if (flag)
      v.push_back(temp);
  }

  // process

  // sorting
  sort(v.begin(), v.end(), [](string a, string b) {
    return (a.length() == b.length()) ? (a < b) : (a.length() < b.length());
  });

  // output
  for (const auto &elem : v) {
    cout << elem << '\n';
  }
}

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  // cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  body();
}