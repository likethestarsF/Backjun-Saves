// 240218 5 #9086
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  while (n--) {
    string str;
    cin >> str;

    cout << str[0];
    cout << str[str.size() - 1];
    cout << '\n';
  }
}