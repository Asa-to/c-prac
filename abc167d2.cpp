#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

int main(void){
    int n; ll k;
    cin >> n >> k;
    int a[60][n];
    rep(i, n){
        cin >> a[0][i];
        a[0][i]--;
    }
    for(int i = 1; i < 60; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = a[i-1][a[i-1][j]];
        }
    }
    int now = 0;
    for(int i = 59; 0 <= i; i--){
        ll l = (1ll << i);
        if(l <= k){
            now = a[i][now];
            k -= l;
        }
    }
    cout << now + 1 << endl;
}