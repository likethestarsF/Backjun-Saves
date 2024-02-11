// 240209 8 #2108
// 240210 1 #2108
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void body() {
  // input
  int n;
  cin >> n;

  vector<int> list(n);
  for (int i = 0; i < n; i++)
    cin >> list[i];

  sort(list.begin(), list.end());

  // average
  double average = 0;
  for (const auto &elem : list)
    average += elem;
  average = round(average / n);

  // median
  auto median = list[n / 2];

  // range: max - min
  int range = list.back() - list.front();

  // mode
  vector<int> mode(range + 1, 0);
  for (int i = 0; i < n; i++) {
    mode[list[i] - list.front()]++;
  }

  int max = *max_element(mode.begin(), mode.end());
  vector<int> maxElem;
  for (int i = 0; i < mode.size(); i++) {
    if (mode[i] == max)
      maxElem.push_back(i + list.front());
  }

  int Mode = (maxElem.size() == 1) ? maxElem[0] : maxElem[1];

  // output
  cout << average + 0.0 << '\n';
  cout << median << '\n';
  cout << Mode << '\n';
  cout << range << '\n';
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