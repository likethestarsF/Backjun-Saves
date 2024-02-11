// 240209 7 #1966
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct printing {
  int priority;
  bool target = false;
};

void body() {
  int caseNum;
  cin >> caseNum;

  while (caseNum--) {
    // input
    int docNum, targetNum;
    cin >> docNum >> targetNum;

    vector<printing> mainQueue(docNum);
    for (int i = 0; i < docNum; i++) {
      cin >> mainQueue[i].priority;
      if (i == targetNum)
        mainQueue[i].target = true;
    }

    for (const auto &elem : mainQueue) {
      clog << "\nelem.priority: " << elem.priority << endl;
      clog << "elem.target: " << elem.target << endl;
    }

    /* Max of docNum is small, so just use Linear Search.
    ** manual style implementation will be done.
    */
    int printed = 0;
    while (true) {
      clog << "\nI am working.\n";
      bool flag = true;
      for (int i = 1; i < mainQueue.size(); i++) {
        // when Higher priority exists in behind.
        if (mainQueue.front().priority < mainQueue[i].priority) {
          printing temp = mainQueue.front();
          mainQueue.erase(mainQueue.begin());
          mainQueue.push_back(temp);
          flag = false;
          clog << "\nFlag is now false!\n";
          break; // exit: for loop.
        }
      }

      // Printing occurs.
      if (flag) {
        printed++;
        clog << "\nprinted increased!\n";
        bool isTargetPrinted = mainQueue.front().target;
        mainQueue.erase(mainQueue.begin());

        if (isTargetPrinted)
          break; // exit: while (true).
      }
    }

    // output
    cout << printed << '\n';
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
