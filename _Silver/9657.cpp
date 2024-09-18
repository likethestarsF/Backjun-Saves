// 240918 1 #9657
// Random Marathon 16 G
// 00:30
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class my {

public:
  void body() {
    /* Input */
    int n;
    cin >> n;

    /** Rule of the Game
     * @DP: If SK wins, DP is true; i stones remain in the SK turn.

     * @Description:
     * 1. we can only take the specific number of stones in one turn: 1, 3 or 4
     * 2. If 'i' stones remain in a turn, SK can make it into i-1, i-3, or i-4.
     * 3. It means, CY will receive the worst case of them: i-1, i-3, or i-4.
     * 4. So, when every of them is true, CY will win; CY must recieve the true.
     * 5. So, SK is goning to lose, if CY wins; we need to use NOT.
     * 5. Thus, DP[i] = !(i-1 && i-3 && i-4); NOT(AND) is used.
     */
    vector<bool> DP(1000 + 1, false);
    DP[1] = true;
    DP[2] = false;
    DP[3] = true;
    DP[4] = true;

    for (int i = 5; i <= n; i++) {
      DP[i] = !(DP[i - 1] && DP[i - 3] && DP[i - 4]);
    }

    if (DP[n])
      cout << "SK";
    else
      cout << "CY";
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
