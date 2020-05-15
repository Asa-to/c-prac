#include <bits/stdc++.h>

using namespace std;

#define rep(a, b) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

int main(void){
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<int> dp(n);
    for(int i = 1; i < n; i++){
        if(s[i-1] == 'A' && s[i] == 'C'){
            dp[i] = dp[i-1] + 1;
        }else{
            dp[i] = dp[i-1];
        }
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        l--;r--;
        cout << dp[r] - dp[l] << endl;
    }
}