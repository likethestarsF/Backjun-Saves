  // 241001 2 #1766
  // Class 5
  // 00:20
  #include <algorithm>
  #include <iostream>
  #include <vector>
  // #define MAX 2147483647
  // #define ll long long
  using namespace std;

  class MY {
    int problemNum, orderNum;
    vector<vector<int>> graph;
    vector<int> inDegree;

  public:
    // MY() {}

    void body() {
      /* Input */
      cin >> problemNum >> orderNum;

      graph.resize(problemNum);
      inDegree.resize(problemNum, 0);
      for (int i = 0; i < orderNum; i++) {
        int parent, child;
        cin >> parent >> child;
        graph[--parent].push_back(--child);
        inDegree[child]++;
      }

      /**
       * 1. Solve All problem : use isSolved & cnt for it.
       * 2. Easier one goes to front. : Use inDegree = 0
       * 3. Smaller one goes to front. : Sort problems that has same inDegree
       */

      // 1.
      vector<bool> isSolved(problemNum, false);
      int isSolvedCnt = 0;
      vector<int> finalResult = {};

      while (isSolvedCnt < problemNum) {
        // 3. automatically sorted because of i = 0, i++
        for (int i = 0; i < problemNum; i++) {
          if (isSolved[i])
            continue;

          // 2-1. make the list to update inDegree later
          if (inDegree[i] == 0) {
            isSolved[i] = true;
            isSolvedCnt++;

            // 2-2. inDegree Update
            for (const int &next : graph[i])
              inDegree[next]--;

            // OUTPUT : Print partial Result step by step
            cout << i + 1 << ' ';
            // start again.
            break;
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

    MY my;
    my.body();
  }
