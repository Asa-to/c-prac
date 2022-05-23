#include <bits/stdc++.h>

using namespace std;

int main(void) {
  string s;
  cin >> s;
  int logest = 0;
  int sum = 0;
  for (int j = 0; j < s.length(); j++) {
    if (s[j] == 'A' || s[j] == 'C' || s[j] == 'G' || s[j] == 'T') {
      sum++;
    } else {
      logest = max(logest, sum);
      sum = 0;
    }
  }
  logest = max(logest, sum);
  cout << logest << endl;
}