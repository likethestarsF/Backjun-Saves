// 240806 3 #16953
// Class 4
// 00:
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define ll long long
using namespace std;

class my {
  ll int A, B;

  ll int Calculation(ll int input, const int type) {
    // Multiply 2 of A
    if (type == 0)
      return (input * 2);

    else {
      string result = to_string(input);
      result = result + '1';
      return stoi(result);
    }
  }

public:
  void body() {
    cin >> A >> B; // [1, 10^9]

    // ### BFS ###
    // initializing
    queue<ll int> q_next = {};
    queue<ll int> q = {};
    q.push(A);

    int cnt = 0 + 1; // the answer should be min + 1, so add 1.
    while (!q.empty()) {
      while (!q.empty()) {
        ll int current = q.front();
        q.pop();

        for (int i = 0; i <= 1; i++) {
          // The answer. we can reach the B
          if (Calculation(current, i) == B) {
            cout << cnt + 1;
            return;
          }

          else if (Calculation(current, i) < B)
            q_next.push(Calculation(current, i));

          // a Case which an adjusted A cannot reach the B.
          // a value bigger than B cannot become B by any operation.
          else if (Calculation(current, i) > B) {
            continue;
          }
        }
      }

      // Storing cnt in the queue requires lots of memory.
      // so, use 2 queues for save cnt.
      q = q_next;
      q_next = {};
      cnt++;
    }

    // an exceptional case when there is no answer
    cout << -1;
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