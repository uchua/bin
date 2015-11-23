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
  string buff, line;
  while (getline(cin,line)) {
    for (char c : line) {
      if (c == ' ') {
        m[buff] += 1;
        buff.clear();
      }
      else {
        // Only include alphabetic characters
        if ((c == '\'' && !buff.empty()) || isalpha(c)) {
          c = toupper(c);
          buff.append(1,c);
        }
      }
    }
    if (!buff.empty()) {
      m[buff] += 1;
      buff.clear();
    }
  }
  for (auto i = m.begin(); i != m.end(); i++) {
    cout << i->first << ',' << i->second << endl;
  }
}
