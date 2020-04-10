#include<bits/stdc++.h>

using namespace std;

/*
*自分より前の全ての数が自分より大きければ、sumにインクリメントしていく
*/
int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    vector<int> dp(n, n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i == 0){
            dp[i] = a[i];
        }else{
            dp[i] = min(dp[i-1], a[i]);
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i] <= dp[i]){
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}