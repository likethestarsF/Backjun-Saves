// 240292 1 #11866
// Josephus problem

/* There are optimized algorithm for this problem.
** But I build the code just mannually.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Josephus {
  vector<int> circle; // initial circular list.
  vector<int> output; // output list.
  int lastIndex = 0;  // index of lastly erased person.

  // find who is the k-th person in circle.
  int findKth(int k) {
    const int size = circle.size();
    clog << "size: " << size << endl;

    int resultIndex = (lastIndex + k) % size;
    resultIndex--;         // vector starts at 0. move the index by -1.
    if (resultIndex == -1) // avoid -1 index.
      resultIndex = size - 1;

    clog << "resultIndex: " << resultIndex << endl;
    return resultIndex;
  }

public:
  // initialize the 1 ~ n circular permutation.
  Josephus(int n) {
    for (int i = 0; i < n; i++) {
      circle.push_back(i + 1);
    }

    for (const auto &i : circle)
      clog << i << " ";
  }

  // add k-th man to output list, and remove k-th man from the circle.
  void pop(int k) {
    int index = findKth(k);
    output.push_back(circle[index]);
    circle.erase(circle.begin() + index);

    lastIndex = index;
  }

  // print out the output list.
  void printOutput() {
    for (int i = 0; i < output.size(); i++) {
      cout << output[i];
      if (i != output.size() - 1)
        cout << ", ";
    }
  }
};

void body() {
  // input
  int n, k;
  cin >> n >> k;

  Josephus josephus(n);

  for (int i = 0; i < n; i++) {
    josephus.pop(k);
  }

  // output
  cout << "<";
  josephus.printOutput();
  cout << ">";
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