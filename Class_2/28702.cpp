// 240929 1 #28702
// Class 2
// 00:15
#include <algorithm>
#include <iostream>
#include <vector>
// #define MAX 2147483647
#define ll long long
using namespace std;

class MY {

  string result(const vector<int> arr) {
    // find the target,
    // since there is always i(non-string) in the arr
    int next = 0;
    for (int i = 0; i < 3; i++) {
      if (arr[i] > 0) {
        next = arr[i] + (3 - i);
        break;
      }
    }

    if (next > 0) {
      if (next % 15 == 0)
        return "FizzBuzz";
      else if (next % 3 == 0)
        return "Fizz";
      else if (next % 5 == 0)
        return "Buzz";
      else
        return to_string(next);
    }

    return "ERROR";
  }

public:
  MY() {}

  void body() {
    /* Input */
    vector<string> input(3);
    for (int i = 0; i < 3; i++)
      cin >> input[i];

    // FizzBuzz : -3 // 15xN
    // Fizz : -2     // 3xN, nonFizzbuzz
    // Buzz : -1     // 5xN, nonFizzbuzz
    // i : i         // everything else

    vector<int> converted(3);
    for (int i = 0; i < 3; i++) {
      if (input[i] == "FizzBuzz")
        converted[i] = -3;
      else if (input[i] == "Fizz")
        converted[i] = -2;
      else if (input[i] == "Buzz")
        converted[i] = -1;
      else
        converted[i] = stoi(input[i]);
    }

    cout << result(converted);
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  MY my;
  my.body();
}
