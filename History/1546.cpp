// 240127 11 #1546
#include <iostream>
#include <string>
using namespace std;

void body() {

  // input
  int n;
  cin >> n;
  float *sc = new float[n];
  for (int i = 0; i < n; i++)
    cin >> sc[i];

  // process
  // choose max
  int max = 0;
  for (int i = 0; i < n; i++) {
    if (max < sc[i]) {
      max = sc[i];
    }
  }
  // re-eavaluate score
  for (int i = 0; i < n; i++) {
    clog << "bef : " << sc[i] << '\n';
    sc[i] = sc[i] / max * 100;
    clog << "Aft : " << sc[i] << '\n';
  }
  // calculate average
  float sum = 0;
  for (int i = 0; i < n; i++) {
    sum += sc[i];
  }
  sum /= n;

  // output
  cout << sum;
}

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  // cin.tie(NULL);
  // cout.tie(NULL);

  /* clog switch */
  std::clog.setstate(std::ios_base::failbit);

  body();
}