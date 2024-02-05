// 240205 2 #2869
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void body() {
  // input
  int a, b, v;
  cin >> a >> b >> v;

  //  process
  int dayInt = (v - a) / (a - b);
  dayInt++;

  dayInt++;
  if ((v - a) % (a - b) == 0)
    dayInt--;

  // output
  cout << dayInt;
}

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  body();
}