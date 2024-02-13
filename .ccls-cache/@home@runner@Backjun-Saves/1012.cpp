// 240212 2 #1012
// 240213 1 #1012
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class farm {
  int width, length, k;
  vector<int> coordinate = {};
  int wormNum = 0;
  int coordXmax, coordYmax;

public:
  void sow() {
    cin >> width >> length; // 1 <= m(x) and n(y) <= 50
    cin >> k;               // k is number of cabbage
    coordXmax = width - 1;
    coordYmax = length - 1;

    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      int coord = x * 100 + y;
      coordinate.push_back(coord);
    }

    sort(coordinate.begin(), coordinate.end());
  }

  void countWorm() {
    while (!coordinate.empty()) {
      int target = coordinate.back();
      wormNum++;
      queue<int> toSearch = {};
      toSearch.push(target);

      while (!toSearch.empty()) {
        int search = toSearch.front();
        toSearch.pop();
        if (binary_search(coordinate.begin(), coordinate.end(), search)) {
          // delete the elem equal to search in coordinate
          coordinate.erase(remove(coordinate.begin(), coordinate.end(), search),
                           coordinate.end());
          int tempX = search / 100;
          int tempY = search % 100;
          // 4-direction search
          /* up */ if (tempY - 1 >= 0)
            toSearch.push(search - 1);
          /*down*/ if (tempY + 1 <= coordYmax)
            toSearch.push(search + 1);
          /*left*/ if (tempX - 1 >= 0)
            toSearch.push(search - 100);
          /*right*/ if (tempX + 1 <= coordXmax)
            toSearch.push(search + 100);
        }
      }
    }
  }

  void output() { cout << wormNum << '\n'; }
  void test() {
    for (const auto &elem : coordinate)
      clog << elem << endl;
  }
};

void body() {
  int t;
  cin >> t; // test case size
  while (t--) {
    farm organic;
    organic.sow();
    // organic.test();
    organic.countWorm();
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