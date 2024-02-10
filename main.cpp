// 240210 5 #18110
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void body() {
  // input
  int n;
  cin >> n;

  vector<int> rating;

  int whileN = n;
  while (whileN--) {
    int input;
    cin >> input;
    rating.push_back(input);
  }

  //  process
  sort(rating.begin(), rating.end());

  int deleted = round(n * 0.15);
  clog << "\ndeleted number : " << deleted << endl;

  float sum = 0;
  for (int i = deleted; i < n - deleted; i++) {
    sum += rating[i];
    clog << "\n rating[i] is : " << rating[i] << endl;
    clog << " sum is : " << sum << endl;
  }

  float divider = n - (deleted * 2);
  clog << "divider " << divider << endl;

  sum /= divider;
  int answer = round(sum);

  // output
  cout << answer;
}

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  std::clog.setstate(std::ios_base::failbit);

  body();
}