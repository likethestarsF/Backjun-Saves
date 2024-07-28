// 240728 1 #8922
// Random Marthon 8 H
// 00:20
#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

class my {
  int maxTest;

  vector<int> makeNextTuple(const vector<int> &tuple) {
    vector<int> result;
    result.resize(tuple.size());
    for (int i = 0; i < tuple.size() - 1; i++) {
      result[i] = abs(tuple[i] - tuple[i + 1]);
    }
    result[tuple.size() - 1] = abs(tuple[tuple.size() - 1] - tuple[0]);

    return result;
  }

public:
  void body() {
    cin >> maxTest;
    while (maxTest--) {

      /* INPUT */
      int tupleSize;
      cin >> tupleSize; // [3, 15]

      vector<int> tuple;
      tuple.resize(tupleSize);

      for (int i = 0; i < tupleSize; i++) {
        cin >> tuple[i]; // [0, 1000]
      }

      /* LOOP */
      bool isLoop = false;
      const vector<int> zeroTuple = vector<int>(tupleSize, 0); // reference

      vector<vector<int>> previousTuples = {};
      previousTuples.push_back(tuple);

      int MAX = 1000;
      while (MAX--) {

        // Make next tuple
        vector<int> nextTuple = makeNextTuple(previousTuples.back());

        if (nextTuple == zeroTuple)
          goto OUTPUT; // Early Exit : ZERO

        // check if is there duplication
        for (int i = 0; i < previousTuples.size(); i++) {
          if (nextTuple == previousTuples[i]) {
            isLoop = true;
            goto OUTPUT; // Early Exit: LOOP
          }
        }

        previousTuples.push_back(nextTuple); // No Duplication
      }

    OUTPUT:
      if (isLoop)
        cout << "LOOP\n";
      else
        cout << "ZERO\n";
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