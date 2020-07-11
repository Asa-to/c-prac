#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    int ans = __gcd(a[0],a[1]);
    for(int i = 2; i < n; i++){
        ans = __gcd(ans, a[i]);
    }
    cout << ans << endl;
}