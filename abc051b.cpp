#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    int k, s, ans = 0;
    cin >> k >> s;
    for(int x = 0; x <= k; x++){
        for(int y = 0; y <= k; y++){
            int z = s - x - y;
            if(z <= k && 0 <= z)ans++;
        }
    }
    cout << ans << endl;
}