#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    int n;
    cin >> n;
    vector<pair<double, string> > a(n);
    rep(i, n)cin >> a[i].first >> a[i].second;
    double btc = 380000;
    double ans = 0;
    rep(i, n){
        if(a[i].second[0] == 'B'){
            a[i].first *= btc;
        }
        ans += a[i].first;
    }
    cout << fixed << setprecision(8) << ans << endl;
}