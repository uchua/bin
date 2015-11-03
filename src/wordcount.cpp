/*
 *  Simple Word Counter
 *  Author: Ian Lantzy
 */

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  map<string,int> m;
  string line, s;
  while (getline(cin,line)) {
    //
  }
  for (auto i = m.begin(); i != m.end(); i++) {
    cout << i->first << ':' << i->second << endl;
  }
}
