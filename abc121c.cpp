#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > a(n);
    rep(i, n)cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    int count = 0, now = 0;
    ll sum = 0;
    while(count < m){
        if(a[now].second){
            a[now].second--;
            sum += a[now].first;
            count++;
        }else{
            now++;
        }
    }
    cout << sum << endl;
}