// 240727 1 #13298
// Random Marthon 8 E
// 00:
#include <algorithm>
#include <iostream>
#include <string>
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
      for (int xtrial = 1; xtrial * l1 <= ltotal; xtrial++) {
        for (int ytrial = 1; ytrial * l2 <= ltotal - xtrial * l1; ytrial++) {

          // find answers for Legs
          if (ltotal - xtrial * l1 == ytrial * l2) {

            // Check if that  answer fits in the Arm case
            if (xtrial * a1 + ytrial * a2 == atotal) {
              if (answerExist) {
                answerExist = false;
                goto END; // early exit
              }

              x = xtrial, y = ytrial;
              answerExist = true;
            }
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