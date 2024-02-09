// 240205 4 #1654
// 240209 1 #1654
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void body() {
  // input
  unsigned int k, n;
  cin >> k >> n;

  unsigned int maxOfLine = 0;
  vector<unsigned int> line(k);
  for (auto i = 0; i < k; i++) {
    cin >> line[i];
    if (maxOfLine < line[i]) // find max length of line.
      maxOfLine = line[i];
  }

  /* n is target we need maximum length of line.
  ** is there any mathematical method? I think, it's not.
  ** what we can do now is brute force or much smarter way than that.
  */

  // we find n according to length.
  // we modify length based on n value by Binary Search.
  // if the result is bigger than n, we increase length.
  // in opposite case, we decrease length.
  // and repeat this process until result and n are same.
  long long rLength = maxOfLine;
  long long lLength = 1;
  long long midLength = (rLength + lLength) / 2; // mL can't be upper bound.
  while (lLength <= rLength) {

    long long nSearch = 0;
    for (const auto &elem : line)
      nSearch += elem / midLength;

    // increase length and update length.
    if (nSearch >= n) {
      lLength = midLength + 1; 
      midLength = (rLength + lLength) / 2;
    }
    // decrease length and update length.
    else {
      rLength = midLength - 1;
      midLength = (rLength + lLength) / 2;
    }
  }

  // output
  cout << midLength;
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
