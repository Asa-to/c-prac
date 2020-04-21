#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, sum = 0;
    cin >> n;
    vector<int> w(n);
    for(int i = 0; i < n; i++){
        cin >> w[i];
        sum += w[i];
    }
    int solve = 0;
    int ans = sum;
    for(int i = 0; i < n; i++){
        solve += w[i];
        ans = min(ans, abs(solve - (sum - solve)));
    }
    cout << ans << endl;
    return 0;
}