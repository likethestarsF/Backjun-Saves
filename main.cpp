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
  int N;

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

public:
  MBTI(int &n) { N = n; }

  void input(string &str) {
    int i = 0;
    person temp;
    temp.isE = str[i] == 'E';
    temp.isS = str[i + 1] == 'S';
    temp.isT = str[i + 2] == 'T';
    temp.isJ = str[i + 3] == 'J';
    list.push_back(temp);
  }

  int min = 12;
  void body() {
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        for (int k = j + 1; k < N; k++) {
          int sum = compare(list[i], list[j]) + compare(list[i], list[k]) +
                    compare(list[j], list[k]);
          min = (sum < min) ? sum : min;
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
    int N;
    cin >> N;

    MBTI a(N);
    while (N--) {
      string str;
      cin >> str;
      a.input(str);
    }

    a.body();
    cout << a.min << '\n';
  }
}