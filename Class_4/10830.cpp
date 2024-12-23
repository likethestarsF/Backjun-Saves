// 241223 1 #10830
// Class 4
// 00:20
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
// #define INF 1e8
// #define MAX 2147483647
#define ll long long
using namespace std;

class MY {
  ll size, exponent;
  vector<vector<int>> matrix;

  template <typename T> T multiply(const T &mat_1, const T &mat_2) {
    T result;
    result.resize(size, vector<int>(size, 0));

    for (int row = 0; row < size; row++) {
      for (int col = 0; col < size; col++) {
        for (int i = 0; i < size; i++) {
          result[row][col] += mat_1[row][i] * mat_2[i][col];
          result[row][col] %= 1000;
        }
      }
    }

    return result;
  }

  template <typename T> T power(const T &matrix, const int &n) {
    if (n == 1)
      return matrix;

    else if (n % 2 == 0) {
      T half = power(matrix, n / 2);
      return multiply(half, half);
    }

    else {
      return multiply(power(matrix, n - 1), matrix);
    }
  }

public:
  MY() {
    cin >> size >> exponent; // [2,5], [1,1e11]
    matrix.resize(size, vector<int>(size, 0));
  }

  void body() {
    /* Input */
    for (int r = 0; r < size; r++)
      for (int c = 0; c < size; c++)
        cin >> matrix[r][c]; // [,1000]

    /* Process */
    vector<vector<int>> answer = power(matrix, exponent);

    /* Output */
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++)
        cout << answer[i][j] << ' ';
      cout << '\n';
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

  MY my;
  my.body();
}
