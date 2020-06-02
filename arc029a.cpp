#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    int n;
    cin >> n;
    vector<int> t(n);
    rep(i, n) cin >> t[i];
    int ans = (1<<30);
    for(int bit = 0; bit < (1<<n); bit++){
        int t1 = 0, t2 = 0;
        for(int i = 0; i < n; i++){
            if(bit&(1<<i))t1 += t[i];
            else t2 += t[i];
        }
        chmin(ans, max(t1, t2));
    }
    cout << ans << endl;
}