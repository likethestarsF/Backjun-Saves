// 240218 4 #11718
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n = 100;
  while (n--) {
    string str;
    getline(cin, str);

    if (str == "")
      break;

    cout << str << '\n';
  }
}