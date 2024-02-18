// 240217 3 #11726
// 240218 1 #11726
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {
  vector<int> DPtable;

public:
  my() {
    DPtable = vector<int>(1000 + 1, 0);
    DPtable[1] = 1;
  }

  int recursiveFill(const int &n) {
    if (n == 0 || n == 1) {
      return 1;
    } else {
      // n-1 :  a 2x1 piece
      // n-2 :  1x2 pieces
      if (DPtable[n] == 0)
        DPtable[n] = recursiveFill(n - 1) + recursiveFill(n - 2);

      return (DPtable[n] % 10007); // prevent the overflow
    }
  }

  void output(const int &n) { cout << DPtable[n] % 10007; }
  void test() {
    for (int elem = 0; elem < DPtable.size(); elem++)
      clog << "DPtable[" << elem << "] = " << DPtable[elem] << endl;
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
  int n;
  cin >> n;
  a.recursiveFill(n);
  a.output(n);
}