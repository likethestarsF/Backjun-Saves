// 240723 1 #21309
// Random Marthon F
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class my {
  int rowSize, colSize;

public:
  vector<vector<bool>> input() {
    cin >> rowSize >> colSize; // [0, 1000]

    vector<vector<bool>> matrix =
        vector<vector<bool>>(rowSize, vector<bool>(colSize));

    for (int row = 0; row < rowSize; row++) {
      for (int col = 0; col < colSize; col++) {
        bool land;
        cin >> land;
        matrix[row][col] = land;
      }
    }

    return matrix;
  }

  // only compare right and down side, to avoid duplicated check
  int cardinal(vector<vector<bool>> matrix) {
    int cardinalSum = 0;

    for (int row = 0; row < rowSize; row++) {
      for (int col = 0; col < colSize; col++) {
        // Is current point Land squre?
        if (matrix[row][col] == false)
          continue;

        // 1. Rightside
        if (col + 1 < colSize) // boundary Check
          if (matrix[row][col + 1] == 1)
            cardinalSum++;

        // 2. downside
        if (row + 1 < rowSize) // boundary Check
          if (matrix[row + 1][col] == 1)
            cardinalSum++;
      }
    }

    return cardinalSum;
  }

  int intercardinal(vector<vector<bool>> matrix) {
    int intercardinalSum = 0;

    // -1 for rowSize to exclude the edge lines of the matrix

    for (int row = 0; row < rowSize; row++) {
      for (int col = 0; col < colSize; col++) {
        // Is current point Land squre?
        if (matrix[row][col] == false)
          continue;

        // 1. left-downward
        if (row - 1 >= 0 && col + 1 < colSize) // boundary Check
          if (matrix[row - 1][col + 1] == 1)
            intercardinalSum++;

        // 2. right-downward
        if (row + 1 < rowSize && col + 1 < colSize) // boundary Check
          if (matrix[row + 1][col + 1] == 1)
            intercardinalSum++;
      }
    }

    return intercardinalSum;
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
  auto mat = a.input();
  int cardinal = a.cardinal(mat);
  int intercardinal = a.intercardinal(mat);
  cout << cardinal << " " << cardinal + intercardinal << endl;
}