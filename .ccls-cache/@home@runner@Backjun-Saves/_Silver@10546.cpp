// 240721 1 #10546 
// Random Marathon
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <unordered_map>
using namespace std;

class my {
  int n;
  unordered_map<string, int> nameList;

public:
  void input() {
    cin >> n;

    // Make a list of total apllied men
    for (int i = 0; i < n; i++) {
      string nameTemp;
      cin >> nameTemp;

      // Case 1 : Same name person already Existed
      if (nameList.find(nameTemp) != nameList.end()) {
        nameList[nameTemp]++;
      }

      // Case 2 : New name person
      else {
        nameList.insert({nameTemp, 1});
      }
    }
  }
  void inputRefining() {
    // input of succeeded men
    for (int i = 0; i < n - 1; i++) {
      string nameTemp;
      cin >> nameTemp;

      // Case 1. erase the key in the map if the value is 1
      if (nameList[nameTemp] == 1) {
        nameList.erase(nameTemp);
      }

      // Case 2. decrease the value by 1 if the value is not 1
      else {
        nameList[nameTemp]--;
      }
    }
  }
  void output() {
    // Check the error
    if (nameList.size() != 1) {
      cout << "?" << endl;
      cout << nameList.size();
      return;
    }

    else {
      cout << nameList.begin()->first;
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
  a.input();
  a.inputRefining();
  a.output();
}