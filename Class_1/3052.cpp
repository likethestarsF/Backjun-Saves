// 240127 7 #3052
#include <iostream>
#include <string>
using namespace std;

void body() {
  // input
  int n[10];
  for (int i = 0; i < 10; i++) {
    cin >> n[i];
  }

  // process
  int list[10];
  int cnt = 0;
  fill_n(list, 10, -1);
  clog << list[0] << list[7];

  for (int i = 0; i < 10; i++) { // i for n[i]
    int temp = n[i] % 42;
    for (int j = 0; j < 10; j++) { // j for list[j]
      if (list[j] != -1 && list[j] == temp) {
        break; // j loop break as same value
      } else if (list[j] == -1) {
        list[j] = temp;
        cnt++;
        break; // j loop break as updated
      }
    }
  }

  // process
  cout << cnt;
}

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  // cout.tie(NULL);

  /* clog switch */
  std::clog.setstate(std::ios_base::failbit);

  body();
}