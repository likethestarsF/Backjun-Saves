// 240807 1 #14919
// Random Marathon 10 H
// 00:
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {
  int m;
  vector<int> numbersCnt;

public:
  void body() {
    // Input
    cin >> m; // [1, 1000]
    numbersCnt.resize(1000, 0);

    string number_str;
    int number;
    while (true) {
      cin >> number_str;

      // eof checker should be placed right behind of the cin.
      if (cin.eof())
        break; // break;
      string num_str_converted = {};

      // manual exit for debug
      // if (number_str == "x")
      // goto EXIT;

      // general cases
      if (number_str.find('.') != string::npos) {
        for (int i = 2; i < number_str.length(); i++) {
          num_str_converted += number_str[i]; // max_length = 6
        }

        // make length as 6
        while (num_str_converted.length() < 6)
          num_str_converted += '0';

        number = stoi(num_str_converted); // [1, 999999]
      }
      // input is 0
      else
        number = 0;

      // Find the where a number belongs
      // : number/1000000 < i / M <-> number * M < i * 1000000
      for (int i = 0; i < m; i++) {
        if ((long long)(number * m) < (long long)((i + 1) * 1000000)) {
          numbersCnt[i]++;
          break;
        }
      }
    }
    // EXIT:

    // Output
    for (int i = 0; i < m; i++)
      cout << numbersCnt[i] << ' ';
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  std::clog.setstate(std::ios_base::failbit);

  my a;
  a.body();
}
