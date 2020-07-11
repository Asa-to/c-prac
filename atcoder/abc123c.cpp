#include <bits/stdc++.h>

using namespace std;

typedef long double ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

int main(void){
    ll n;
    vector<ll> a(5);
    cin >> n >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
    sort(a.begin(), a.end());
    ll ans = ceil(n / a[0]) + 4;
    cout << fixed << setprecision(0) <<  ans << endl;
}