// 240730 1 #15650
// Class 4
// 00:30
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {
  int N, M;
  vector<int> sequence;

  void print() {
    for (const auto &i : sequence) {
      cout << i << ' ';
    }
    cout << '\n';
  }

  int simulate() {
    int result = M - 1;

    while (true) {
      // last elem of the sequence should be not greater than N
      if (sequence[result] + 1 + M - (result + 1) <= N)
        break;
      else
        result--;
    }

    return result;
  }

public:
  void body() {
    // Input
    cin >> N >> M; // [1, 8]
    sequence.resize(M);
    for (int i = 0; i < M; i++) {
      sequence[i] = i + 1;
    }
    print();

    // Process
    int index = M - 1;
    while (true) {
      if (sequence[0] == N - M + 1)
        break;

      // find the last point that can be added.
      index = simulate();

      sequence[index]++;
      for (int i = index + 1; i < M; i++)
        sequence[i] = sequence[i - 1] + 1;

      // print
      print();
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