// 240211 6 #11399
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void body() {
  // input
  int n;
  cin >> n;
  vector<int> time(n);
  for (int i = 0; i < n; i++) {
    cin >> time[i];
  }
  sort(time.begin(), time.end());

  //  process
  int totalTime = 0;
  int eachTime = 0;
  for (const auto &elem : time) {
    eachTime += elem;
    totalTime += eachTime;
  }

  // output
  cout << totalTime;
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