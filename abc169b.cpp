#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    ll maxd = 1e18;
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    sort(a.begin(), a.end());
    if(a[0] == 0){
        cout << 0 << endl;
        return 0;
    }
    ll sum = 1;
    for(ll i: a){
        if(maxd / i < sum){
            cout << -1 << endl;
            return 0;
        }else{
            sum *= i;
        }
    }
    cout << sum << endl;
}