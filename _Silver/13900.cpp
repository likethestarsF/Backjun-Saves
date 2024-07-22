// 240722 1 #13900
// Random Marathon G
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {
  int n;

public:
  void body() {
    cin >> n;

    long long int prevSum = 0;
    long long int answerSum = 0;
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      answerSum += prevSum * temp;
      prevSum += temp;
    }

    cout << answerSum;
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
  a.body();
}