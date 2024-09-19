// 240919 2 #2143
// Class 5
// 00:40
#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

class my {
  template <typename T> void testArr(T k, bool exitFlag) {
    for (auto e : k)
      clog << e << endl;
    if (exitFlag)
      exit(1);
  }

  int T, a_size, b_size;
  vector<int> a_arr, b_arr; // [-10^6, 10^6]

  vector<int> MakeSubArr(const vector<int> &arr) {
    vector<int> result = {};

    for (int start = 0; start < arr.size(); start++) {
      ll sum = arr[start];
      result.push_back(sum);
      for (int i = start + 1; i < arr.size(); i++) {
        sum += arr[i];
        result.push_back(sum);
      }
    }

    return result;
  }

public:
  void body() {
    /* Input */
    cin >> T; // [-10^9, 10^9], [1, 1000]

    cin >> a_size;
    a_arr.resize(a_size);
    for (int i = 0; i < a_size; i++)
      cin >> a_arr[i];
    cin >> b_size;
    b_arr.resize(b_size);
    for (int i = 0; i < b_size; i++)
      cin >> b_arr[i];

    /* Main */
    // 1. make Sub array: Prefix Sum
    vector<int> a_sub = MakeSubArr(a_arr);
    vector<int> b_sub = MakeSubArr(b_arr);
    sort(b_sub.begin(), b_sub.end()); // sort for the B.S.

    // Sequentially select a_sub -> find proper b_sub by Binary Search
    int cnt = 0;
    for (int i = 0; i < a_sub.size(); i++) {
      const int target = T - a_sub[i];

      // Binary Search
      int low = lower_bound(b_sub.begin(), b_sub.end(), target) - b_sub.begin();
      int upp = upper_bound(b_sub.begin(), b_sub.end(), target) - b_sub.begin();
      cnt += (upp - low);
    }

    cout << cnt;
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
