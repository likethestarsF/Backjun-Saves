// 240727 1 #13298
// Random Marthon 8 E
// 00:50
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class my {

public:
  void body() {
    int n;
    cin >> n;

    while (n--) {
      int l1, l2, ltotal;
      int a1, a2, atotal; // [1,10000]
      // ltotal =  x*l1  + y*l2
      // atotal =  x*a1  + y*a2

      cin >> l1 >> a1 >> l2 >> a2 >> ltotal >> atotal;

      bool answerExist = false;
      int x = -1, y = -1;
      for (int xtrial = 1; l1 * xtrial < ltotal; xtrial++) {

        // find divisors(y) for Legs
        const int residual = ltotal - l1 * xtrial;
        if (residual % l2 == 0) {
          int ytrial = residual / l2;

          // Check if the answer is valid in Arms
          if (a1 * xtrial + a2 * ytrial == atotal) {
            if (answerExist) {
              answerExist = false;
              goto END; // early exit
            }

            answerExist = true;
            x = xtrial;
            y = ytrial;
          }
        }
      }

    END:
      if (answerExist)
        cout << x << " " << y << "\n";
      else
        cout << "?\n";
    }
  }

  vector<int> divisorFinder(int target) {
    vector<int> result = {};
    for (int i = 1; i <= (int)sqrt(target); i++) {
      if (target % i == 0) {
        result.push_back(i);

        if ((target / i) != i)
          result.push_back(target / i);
      }
    }

    return result;
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