// 240209 4 #7568
/* Use struct.
** Will it not cause the timeout to caculate the rank one by one?
** that is the easiest way, but it seems cause timeout.
** Save the order in struct, and at first, sort by the weight.
** Calculate the rank and sort again by order.
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct man {
  short weight;
  short height;
  short order;
  short rank = 1;
};

bool compareWH(const man &a1, const man &a2) {
  return (a1.weight == a2.weight) ? a1.height > a2.height
                                  : (a1.weight > a2.weight);
}

bool compareOrder(const man &a1, const man &a2) { return a1.order < a2.order; }

void body() {
  // input
  short n;
  cin >> n;

  vector<man> list(n);
  for (int i = 0; i < n; i++) {
    list[i].order = i;
    cin >> list[i].weight >> list[i].height;
  }

  // comparator : heaviest person goes front,
  // if weight is same, taller person goes first.
  sort(list.begin(), list.end(), compareWH);

  /* Calculate the rank. We count the bigger person than oneself.
  ** those behind of me is not bigger than me. <- don't need to care about.
  ** those who in front of me is able to bigger than me,
  ** when he is taller than me. and also heavier than me..
  */
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (list[i].height < list[j].height && list[i].weight < list[j].weight)
        list[i].rank++;
    }
  }

  for (const auto &elem : list)
    clog << elem.order << " " << elem.weight << " " << elem.height << " "
         << elem.rank << endl;

  // Re-sort by initial order.
  sort(list.begin(), list.end(), compareOrder);
  // output
  for (int i = 0; i < n; i++) {
    cout << list[i].rank << ' ';
  }
}

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  std::clog.setstate(std::ios_base::failbit);

  body();
}