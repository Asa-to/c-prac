#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    ll N;
    cin >> N;
    string ans = "";
    while(N){
        N--;
        ans += 'a' + N % 26;
        N /= 26;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}