// 240131 3 #1920
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void body() {
  // input
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto i = 0; i < n; i++) {
    cin >> a[i];
  }

  int m;
  cin >> m;

  vector<int> b(m);
  for (auto i = 0; i < m; i++) {
    cin >> b[i];
  }

  //  process

  // sort a vector.
  sort(a.begin(), a.end());
  clog << "\nA vector : " << a[0] << ',' << a[1] << '\n';

  // make vector for output.
  vector<bool> output(m);

  // loop for each element in b. output will be 1 if b_elem is in a.
  // Use binary search.
  for (auto i = 0; i < m; i++) {
    output[i] = binary_search(a.begin(), a.end(), b[i]);

    // output
    cout << output[i] << '\n';
  }
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