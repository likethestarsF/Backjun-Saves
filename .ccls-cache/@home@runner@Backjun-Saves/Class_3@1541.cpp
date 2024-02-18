// 240218 10 #1541
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {
  vector<int> numbers = {};
  bool conversionToMinus = false;

public:
  void in() {
    string math;
    getline(cin, math);
    string num = {};
    for (const auto &c : math) {

      if (c == '+' || c == '-') { // + is -1, - is -2
        numbers.push_back(stoi(num));
        num.erase();
        if (c == '+')
          numbers.push_back(-1);
        else
          numbers.push_back(-2);
      }

      else
        num.append(1, c);
    }
    numbers.push_back(stoi(num)); // last number element

    // for (const auto &e : numbers) // for test
    //   clog << e << endl;
  }

  void findMin() {
    int size = numbers.size();
    int total = numbers[0];
    for (int index = 0; index < size; index++) {

      if (numbers[index] == -1) { // '+'
        if (conversionToMinus)
          total -= numbers[index + 1];
        else
          total += numbers[index + 1];

      } else if (numbers[index] == -2) { // '-'
        total -= numbers[index + 1];
        // '+' behind this '-' can be always converted into '-'
        conversionToMinus = true;

        // pass the int : adding is done when index directs operator
      } else {
        continue;
      }
    }

    cout << total;
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
  a.in();
  a.findMin();
}