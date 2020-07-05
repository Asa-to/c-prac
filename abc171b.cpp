#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i,N)cin >> a[i];
    sort(a.begin(), a.end());
    ll sum = 0;
    rep(i, K)sum += a[i];
    cout << sum << endl;
}