// 240308 1 #17626
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class FourSquares {
  vector<int> listOfSquares = {};
  vector<int> listOfSquares2 = {};
  int n;

public:
  FourSquares(int &num) {
    n = num;
    // update n^2 in the range
    for (int i = 1; i * i <= n; i++) {
      listOfSquares.push_back(i * i);
    }
  }

  int result = 0;

  void body() {
    // Case 1 : n is square number
    if (listOfSquares.back() == n) {
      result = 1;
      return;
    }

    // Case 2 : choose two square numbers from listOfsquares
    for (int i1 = 0; i1 < listOfSquares.size(); i1++) {
      for (int i2 = i1 + 1; i2 < listOfSquares.size(); i2++) {
        int sum = listOfSquares[i1] + listOfSquares[i2];
        if (sum == n) {
          result = 2;
          return;
        }
        // save sum of 2 square numbers
        else {
          listOfSquares2.push_back(sum);
        }
      }
    }

    // Case 3 : choose a number from listOfSquares and a num from list2
    for (int i1 = 0; i1 < listOfSquares.size(); i1++) {
      for (int i2 = 0; i2 < listOfSquares2.size(); i2++) {
        int sum = listOfSquares[i1] + listOfSquares2[i2];
        if (sum == n) {
          result = 3;
          return;
        }
      }
    }

    // Case 4 : must be 4 'cause it's not the case 1~3
    result = 4;
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  int n;
  cin >> n;
  FourSquares a(n);
  a.body();
  cout << a.result;
}