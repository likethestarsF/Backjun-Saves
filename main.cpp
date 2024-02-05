// 240205 4 #1654
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

unsigned long long findN(const vector<int> &line, int length) {
  unsigned long long sum = 0;
  for (const int &elem : line)
    sum += (unsigned long long)(elem / length);
  return sum;
}
void body() {
  // input
  unsigned int k, n;
  cin >> k >> n;

  int maxOfLine = 0;
  vector<int> line(k);
  for (int i = 0; i < k; i++) {
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
  long rLength = maxOfLine;
  long lLength = 1;
  long midLength = (rLength - lLength) / 2;
  while (true) {
    unsigned long long nSearch = findN(line, midLength);

    // increase length and update length.
    if (nSearch > n) {
      lLength = midLength;
      midLength = (rLength - lLength) / 2;
    }
    // decrease length and update length.
    else if (nSearch < n) {
      lLength = midLength;
      midLength = (rLength - lLength) / 2;
    }
    // n == result(midLength).
    else {
      break;
    }
  }

  // we have to find biggest length.
  // when result and n are same,
  // we increase length by 1 until n and result is different.
  // if we decrease by 1 to result, that is the answer.
  while (true) {
    midLength++;
    if (n != findN(line, midLength))
      break;
  }
  midLength--;

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
