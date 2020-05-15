#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

/**
 * @param {vector<pair<int, int>> a} データ
 * @param {int begin} index
 * @return {int count} a[begin]の上映中に見れる動画の数
*/
int solve(vector<pair<int, int> > a, int begin){
    int count = 0, end = a[begin].second;
    for(int i = )
}

int main(void){
    int n;
    cin >> n;
    vector<pair<int, int> > a(n);
    rep(i,n)cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    int time = 0, count = 0;
    for(int i = 0; i < n; i++){
        if(time < a[i].first){
            time = a[i].first;
            time += a[i].second;
            count++;
        }
    }
    cout << count << endl;
}