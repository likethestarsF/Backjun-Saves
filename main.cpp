// 240214 6 #1927
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int heap(vector<int> &v) {
  if (v.empty()) {
    return 0;
  } else {
    sort(v.begin(), v.end(), greater<int>());
    int temp = v.back();
    v.pop_back();
    return temp;
  }
}

void body() {
  // input
  int n;
  cin >> n;

  vector<int> v = {};
  while (n--) {
    unsigned int inp;
    cin >> inp;
    if (inp == 0)
      cout << heap(v) << '\n';
    else {
      v.push_back(inp);
    }
  }

  // output
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