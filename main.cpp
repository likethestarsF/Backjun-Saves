// 240216 4 #9095
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct tri {
  int d[4] = {0, 0, 0, 0};

  bool operator<(const tri &other) const {
    for (int i = 1; i < 4; i++) {
      if (d[i] != other.d[i]) {
        return d[i] < other.d[i];
      }
    }
    return false;
  }
};

class my {
  vector<int> dptable;

  // need to use dp
  int fact(const int &n) {
    if (dptable[n] == 0)
      dptable[n] = n * fact(n - 1);
    return dptable[n];
  }

public:
  vector<int> cnt;
  my() {
    dptable = vector<int>(12, 0);
    dptable[0] = 1;
    dptable[1] = 1;
  }

  void IO(int t) {
    while (t--) {
      int n;
      cin >> n;

      cout << body(n) << '\n'; // returns the answer
    }
  }

  void spreading1(int &n, set<tri> &table) {
    for (int numOfN = 1; numOfN <= n; numOfN++) {
      // initialize vector which size is numOfN
      vector<int> digits = vector<int>(numOfN, 0);
      // 2 wrong cases: Exist over 3 or 0. - check by flag
      bool flag_numOfN = true;

      int timesCnt = 0;
      while (timesCnt < n) { // add n times
        for (int i = 0; i < numOfN; i++) {
          if (timesCnt == n)
            break;
          digits[i]++;
          timesCnt++;
        }

        if (digits[0] > 3) { // wrong case 1
          flag_numOfN = false;
          break;
        }
      }
      if (digits.back() == 0) // wrong case 2
        flag_numOfN = false;

      // add the case to the table :excluding the wrong cases
      if (flag_numOfN) {
        // count the number of 1,2,3
        tri temp;
        for (const auto &elem : digits)
          temp.d[elem]++;

        table.insert(temp); // submit
      }
    }
  }

  void concetrated1(int &n, set<tri> &table) {
    for (int numOfN = 1; numOfN <= n; numOfN++) {
      // initialize vector which size is numOfN
      vector<int> digits = vector<int>(numOfN, 0);
      // 2 wrong cases: Exist over 3 or 0. - check by flag
      bool flag_numOfN = true;

      // spreading 1st to 1 for every elem
      int timesCnt = 0;
      for (int i = 0; i < numOfN; i++) {
        digits[i]++;
        timesCnt++;
      }

      if (timesCnt > n)
        flag_numOfN = false; // wrong case: 1st spreading cannot be done.

      while (timesCnt < n) { // add n times
        for (int i = 0; i < digits.size();) {
          if (timesCnt == n)
            break;

          digits[i]++;
          timesCnt++;

          if (digits[i] == 3)
            i++;
          if (i == digits.size()) {
            goto Exit;
          }
        }
      }
    Exit: // wrong case if adding is not completely done.
      if (timesCnt < n) {
        flag_numOfN = false;
      }

      // add the case to the table :excluding the wrong cases
      if (flag_numOfN) {
        // count the number of 1,2,3
        tri temp;
        for (const auto &elem : digits)
          temp.d[elem]++;

        table.insert(temp); // submit
      }
    }
  }

  void fixed3(int &n, set<tri> &table) {
    for (int numOfN = 1; numOfN <= n; numOfN++) {
      // initialize vector which size is numOfN
      vector<int> digits = vector<int>(numOfN, 0);
      // 2 wrong cases: Exist over 3 or 0. - check by flag
      bool flag_numOfN = true;

      int num3 = n / 3;
      int flag3 = false;
      if (num3 < numOfN) {
        flag3 = true;
        for (int i = 0; i < num3; i++)
          digits[i] = 3;
      }

      int timesCnt = num3 * 3;
      int k = 0;
      if (flag3) {
        k = num3 - 1;
      }
      while (timesCnt < n) { // add n times
        for (int i = k; i < numOfN; i++) {
          if (timesCnt == n)
            break;
          digits[i]++;
          timesCnt++;
        }

        if (digits[k] > 3) { // wrong case 1
          flag_numOfN = false;
          break;
        }
      }
      if (digits.back() == 0) // wrong case 2
        flag_numOfN = false;

      // add the case to the table :excluding the wrong cases
      if (flag_numOfN) {
        // count the number of 1,2,3
        tri temp;
        for (const auto &elem : digits)
          temp.d[elem]++;

        table.insert(temp); // submit
      }
    }
  }

  int body(int n) {
    set<tri> table;

    // making the table
    // case 1: spread the 1
    spreading1(n, table);
    // case 2 : concentrated adding
    // concetrated1(n, table);
    fixed3(n, table);

    // finish to store the every possible cases in table.
    // count possible cases using mathmathecal method
    int totCnt = 0;
    // clog << "\nfor reached: " << table.size() << endl;
    for (auto it = table.begin(); it != table.end(); it++) {
      int totalDigits = it->d[1] + it->d[2] + it->d[3];
      int partCnt = fact(totalDigits) /
                    (fact(it->d[1]) * fact(it->d[2]) * fact(it->d[3]));
      totCnt += partCnt;
      clog << "partCnt :" << partCnt << '\n';
    }

    return totCnt;
  }

  void o() { cout << fact(11); }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  my a;
  int t;
  cin >> t;
  a.IO(t);
}