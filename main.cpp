// 240212 2 #1012
// 240213 1 #1012
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class farm {
  int t;
  int width, length, k;
  vector<vector<bool>> field;
  vector<vector<bool>> safe;

public:
  void sow() {
    cin >> width >> length; // 1 <= m(x) and n(y) <= 50
    cin >> k;               // k is number of cabbage

    field = vector<vector<bool>>(length, vector<bool>(width, false));
    for (int i = 0; i < k; i++) {
      int xTemp, yTemp;
      cin >> xTemp >> yTemp;
      field[xTemp][yTemp] = true;
    }
  }
  void output() {}
};

void body() {
  int t;
  cin >> t; // test case size
  while (t--) {
    farm organic;
    organic.sow();
    organic.output();
  }
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