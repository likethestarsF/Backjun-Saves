// 240218 8 #1015
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct intt {
  int a;
  int order;
};

bool compare(intt a1, intt a2) {
  return (a1.a != a2.a) ? a1.a < a2.a : a1.order < a2.order;
};

class my {
  vector<intt> A;
  vector<int> P;

public:
  void in(const int &n) {
    for (int i = 0; i < n; i++) {
      intt num;
      num.order = i;
      cin >> num.a;
      A.push_back(num);
    }
  }

  void findP() {
    sort(A.begin(), A.end(), compare);
    P.resize(A.size());
    for (int i = 0; i < A.size(); i++) {
      P[A[i].order] = i;
    }
  }

  void out() {
    for (const auto &elem : P)
      cout << elem << ' ';
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
  a.in(n);
  a.findP();
  a.out();
}