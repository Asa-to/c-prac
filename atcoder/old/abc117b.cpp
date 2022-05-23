#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    int N;
    cin >> N;
    vector<int> l(N);
    rep(i , N)cin >> l[i];
    sort(l.begin(), l.end());
    int sum = 0;
    rep(i, N-1){
        sum += l[i];
    }
    string ans = l[N-1] < sum ? "Yes" : "No";
    cout << ans << endl;
}