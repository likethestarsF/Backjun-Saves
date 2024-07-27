  // 240727 2 #13567
  // Random Marthon 8 E
  // 00:40
  #include <algorithm>
  #include <iostream>
  #include <string>
  #include <vector>
  using namespace std;
  
  struct coord {
    int x = 0, y = 0;  // (x, y)
    int direction = 1; // 0: Up, 1 : Right, 2 : Down, 3 : Left
  };
  
  class my {
    int mapSize, cmdLines;
    coord point;
    bool isError = false;
  
    coord excute(const coord &target, const string &cmdS, const int &cmdN) {
      coord result = target;
      if (cmdS == "TURN") {
        switch (cmdN) {
        case 0: // Turn Left
          result.direction--;
          if (result.direction == -1)
            result.direction = 3;
          break;
  
        case 1: // Turn Right
          result.direction++;
          if (result.direction == 4)
            result.direction = 0;
          break;
  
        default:
          break;
        }
      }
  
      else if (cmdS == "MOVE") {
        switch (result.direction) {
        case 0:
          result.y += cmdN;
          break;
        case 1:
          result.x += cmdN;
          break;
        case 2:
          result.y -= cmdN;
          break;
        case 3:
          result.x -= cmdN;
          break;
        default:
          break;
        }
      }
  
      else {
        cerr << "error in commandline" << endl;
      }
  
      return result;
    }
  
  public:
    void body() {
      cin >> mapSize >> cmdLines;
      while (cmdLines--) {
        string cmdS;
        int cmdN;
        cin >> cmdS >> cmdN;
  
        // Excute the commands
        if (isError)
          continue;
  
        // simulate if it is possible
        coord simulation = excute(point, cmdS, cmdN);
  
        if (simulation.x < 0 || simulation.y < 0 || simulation.x > mapSize ||
            simulation.y > mapSize) {
          isError = true;
        } else
          point = simulation;
      }
  
      // Output
      if (isError) {
        cout << -1;
      } else
        cout << point.x << ' ' << point.y;
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