// 240211 7 #17219
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

void body() {
  // input
  int siteSaved, siteToFind;
  cin >> siteSaved >> siteToFind;

  map<string, string> siteMap;
  for (int i = 0; i < siteSaved; i++) {
    string site, pwd;
    cin >> site >> pwd;
    siteMap.insert({site, pwd});
  }

  //  process
  for (int i = 0; i < siteToFind; i++) {
    string site;
    cin >> site;
    cout << siteMap[site] << '\n';
  }
}

int main() {
  /* cin optimize */
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /* clog switch */
  // std::clog.setstate(std::ios_base::failbit);

  body();
}