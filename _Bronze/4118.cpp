// 240809 2 #4118
// Random Marathon 10 C
// 00:15
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {
  int ticketSize;
  vector<bool> isBought;

  bool IsAllPurchased() {
    // input Lotto numbers
    for (int i = 0; i < ticketSize; i++) {
      for (int j = 0; j < 6; j++) {
        int temp;
        cin >> temp;
        isBought[temp] = true;
      }
    }

    // Check if everything is purchased
    for (int i = 1; i < 50; i++)
      if (isBought[i] == false)
        return false;

    return true;
  }

public:
  void body() {
    while (true) {
      cin >> ticketSize; // [1, 100]

      if (ticketSize == 0)
        return;

      isBought = vector<bool>(50, false); // [0] isn't used
      if (IsAllPurchased())
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  my a;
  a.body();
}