// 240000 1 #00
// Class X
// 00:
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {

public:
template <typename T> void testArr(T k, bool exitFlag) {
  for (auto e : k)
    clog << e << endl;
  if (exitFlag)
    exit(1);
}

  void body() {

    
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