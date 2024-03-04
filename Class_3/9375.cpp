// 240305 1 #9375
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class my {
  int numOfClothes;
  unordered_map<string, int> clothes; // <category, number>
  vector<int> numOfEachClothes = {};

public:
  void input() {
    cin >> numOfClothes;
    for (int i = 0; i < numOfClothes; i++) {
      string name;
      string category;
      cin >> name >> category;

      // add category to the map
      if (clothes.find(category) == clothes.end()) {
        clothes.insert({category, 1});
      } else
        clothes[category]++;
    }
  }

  /* Use nPr.
  ** 1. Add 1 to every elems of clothes,
  **it is when none is chosen in that category.
  ** 2. Then Apply nPr - 1.
  **-1 is to exclude none is chosen in every category: naked.
  */
  int numOfCases() {
    if (clothes.empty())
      return 0; // no clothes

    int result = 1;
    for (auto &i : clothes) {
      result *= (i.second + 1);
    }
    return (result - 1);
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  int t;
  cin >> t;
  while (t--) {
    my a;
    a.input();
    cout << a.numOfCases() << '\n';
  }
}