// 240928 1 #11444
// Class 4
// 00:20
#include <algorithm>
#include <iostream>
#include <vector>
// #define MAX 2147483647
#define ll long long
using namespace std;

class MY {
  // def matrixBasic
  const vector<vector<ll>> matrixBasic = {{1, 1}, {1, 0}};
  const vector<vector<ll>> matrixDiagonal = {{1, 0}, {0, 1}};

  // Recursive ^n = (^n/2)^2
  vector<vector<ll>> fibo(const ll &n) {
    if (n == 0)
      return matrixDiagonal;
    if (n == 1)
      return matrixBasic;

    vector<vector<ll>> mat = fibo(n / 2);

    if (n % 2 == 0)
      return multiplication(mat, mat);
    else
      return multiplication(multiplication(mat, mat), matrixBasic);
  }

  vector<vector<ll>> multiplication(const vector<vector<ll>> &mat1,
                                    const vector<vector<ll>> &mat2) {

    vector<vector<ll>> result(2, vector<ll>(2));
    result[0][0] = mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0];
    result[0][1] = mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1];
    result[1][0] = mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0];
    result[1][1] = mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1];

    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        result[i][j] %= 1000000007;

    return result;
  }

public:
  MY() {}

  void body() {
    /* Input */
    ll input;
    cin >> input; // N[,1e18]

    /** Main
     * ( 1 1 )^n = Fn-1 Fn
     * ( 1 0 )     Fn Fn-2
     */
    auto answer = fibo(input);
    cout << answer[0][1] % 1000000007;

    // why multiply is done 1 more time?
    // is it because of the diagonal?
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
