// 240131 5 #10814
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

void body() {
  // input
  int n;
  cin >> n;

  // tuple vector; Signin order, age, name
  vector<tuple<int, int, string>> a(n);

  for (int i = 0; i < n; i++) {
    int temp_i;
    string temp_s;
    cin >> temp_i >> temp_s;
    a[i] = make_tuple(i, temp_i, temp_s);
  }

  //  process
  // sort by STL sort
  sort(a.begin(), a.end(),
       // make comparator by lambda function; age is 1st, Signin order is 2nd
       [](tuple<int, int, string> a, tuple<int, int, string> b) {
         return (get<1>(a) != get<1>(b)) ? (get<1>(a) < get<1>(b))
                                         : (get<0>(a) < get<0>(b));
       });

  // output
  for (int i = 0; i < n; i++) {
    cout << get<1>(a[i]) << ' ' << get<2>(a[i]) << '\n';
  }
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