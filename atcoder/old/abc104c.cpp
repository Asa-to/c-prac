#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    int d, g;
    cin >> d >> g;    
    vector<int> p(d);
    vector<int> c(d);
    rep(i, d)cin >> p[i] >> c[i];
    int ans = (1<<30);
}