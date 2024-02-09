// 240209 5 #11651
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct cord {
  int x;
  int y;
};

bool compareYX(cord a1, cord a2) {
  return (a1.y == a2.y) ? a1.x < a2.x : a1.y < a2.y;
}

void body() {
  // input
  int n;
  cin >> n;

  vector<cord> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].x >> v[i].y;
  }

  sort(v.begin(), v.end(), compareYX);

  // output
  for (const auto &elem : v)
    cout << elem.x << ' ' << elem.y << '\n';
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