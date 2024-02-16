// 240216 2 #1931
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct meeting {
  unsigned int start, end;
};

bool compare(const meeting &a1, const meeting &a2) {
  return (a1.end == a2.end) ? a1.start < a2.start : a1.end < a2.end;
}

class reservation {
  vector<meeting> timetable;
  int begin = 0;

public:
  int cnt = 0;
  void input(int n) {
    while (n--) {
      unsigned int start, end;
      cin >> start >> end;
      meeting temp = {start, end}; // init length is end
      timetable.push_back(temp);
    }
  }

  void sorting() { sort(timetable.begin(), timetable.end(), compare); }

  void body() {
    // choose a initial meeting
    sorting();
    begin = timetable[0].end;
    cnt++;

    int index = 0;
    int i = 0;
    while (true) {
      for (i = index + 1; i < timetable.size(); i++) {
        if (timetable[i].start >= begin) {
          begin = timetable[i].end;
          cnt++;
          index = i;
          break;
        }
      }

      if (i >= timetable.size())
        break; // exit : while
    }
  }

  void out_timetable() {
    for (int i = 0; i < timetable.size(); i++)
      cout << timetable[i].start << " " << timetable[i].end << endl;
  }
};

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  int n;
  cin >> n;
  reservation a;
  a.input(n);

  a.body();
  cout << a.cnt;
}