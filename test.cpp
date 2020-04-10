#include <bits/stdc++.h>

using namespace std;

int main(void){
  int ans = 0;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    ans += 3 * pow(10,i);
    cout << 3 * pow(10,i) << " i = " << i << " ans = " << ans << endl;
  }
  cout << ans << endl;
  return 0;
}