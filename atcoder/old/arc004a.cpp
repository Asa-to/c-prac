#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

double getDis(pair<int, int> a, pair<int, int> b){
    return pow(pow(b.first - a.first,2) + pow(b.second - a.second, 2), 0.5);
}

int main(void){
    int n;
    cin >> n;
    vector<pair<double, double> > a(n);
    rep(i,n)cin >> a[i].first >> a[i].second;
    double maxd = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            chmax(maxd, getDis(a[i], a[j]));
        }
    }
    cout << fixed << setprecision(10) << maxd << endl;
}