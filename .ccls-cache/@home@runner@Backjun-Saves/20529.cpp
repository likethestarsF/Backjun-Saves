// 240308 2 #20529
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct person {
  bool isE, isS, isT, isJ;
};

class MBTI {
  vector<person> list = {};
  vector<int> check = {};

  int compare(person &a, person &b) {
    int distance = 4;

    if (a.isE == b.isE)
      distance--;
    if (a.isS == b.isS)
      distance--;
    if (a.isT == b.isT)
      distance--;
    if (a.isJ == b.isJ)
      distance--;

    return distance;
  }

  int transToInt(person &a) {
    int result = 0;
    result += a.isE * 8;
    result += a.isS * 4;
    result += a.isT * 2;
    result += a.isJ;
    return result;
  }

public:
  MBTI() { check.resize(16, 0); }

  void input(string &str) {
    int i = 0;
    person temp;
    temp.isE = str[i] == 'E';
    temp.isS = str[i + 1] == 'S';
    temp.isT = str[i + 2] == 'T';
    temp.isJ = str[i + 3] == 'J';

    // MBTI 16 cases :  0000(INFP) ~ 1111(ESTJ)
    int temp_int = transToInt(temp);

    // push_back the same elem less than 4 times (maximum 3 times)
    if (check[temp_int] < 3) {
      check[temp_int]++;
      list.push_back(temp);
    }
  }

  int min = 12;
  void body() {
    int N = list.size();
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        for (int k = j + 1; k < N; k++) {
          int sum = compare(list[i], list[j]) + compare(list[i], list[k]) +
                    compare(list[j], list[k]);
          min = (sum < min) ? sum : min;

          if (min == 0)
            return;
        }
      }
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

  int T;
  cin >> T;
  while (T--) {
    MBTI a;

    int N;
    cin >> N;

    while (N--) {
      string str;
      cin >> str;
      a.input(str);
    }

    a.body();
    cout << a.min << '\n';
  }
}