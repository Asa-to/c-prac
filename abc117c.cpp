#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    int n, m;
    cin >> n >> m;
    vector<pair<int, bool> > x(m);
    rep(i, m)cin >> x[i].first;
    if(m <= n){
        cout << 0 << endl;
    }
}