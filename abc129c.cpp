#include<bits/stdc++.h>

using namespace std;

void print(vector<long long> dp){
    cout << "----------------------" << endl;
    for(auto i: dp){
        cout << i << endl;
    }
    cout << "----------------------" << endl;
}

int main(void){
    long long mod = 1000000007;
    int n, m;
    cin >> n >> m;
    vector<long long> dp(n+100);
    dp[0] = 1;
    vector<bool> a(n+100, true);
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        a[temp] = false;
    }
    for(int i = 0; i <= n; i++){
        dp[i] %= mod;
        if(a[i+1]){
            dp[i+1] += dp[i];
        }
        if(a[i+2]){
            dp[i+2] += dp[i];
        }
    }
    cout << dp[n] << endl;
    return 0;
}