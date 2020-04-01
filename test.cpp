#include <bits/stdc++.h>

using namespace std;

int n;
int R[200009];

int main(void){
  cin >> n;
  cin >> R[0];
  int maxj = -999999999;
  int minj = R[0];
  for(int i = 1; i < n; i++){
    cin >> R[i];
    maxj = max(maxj, R[i] - minj);
    minj = min(minj, R[i]);
  }
  cout << maxj << endl;
  return 0;
}