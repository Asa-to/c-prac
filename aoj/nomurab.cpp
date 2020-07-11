#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    string t;
    cin >> t;
    int ans = t[0] != 'P' ? 1 : 0;
    if(t[0] == '?')t[0] = 'D';
    for(int i = 1; i < t.length(); i++){
        if(t[i] == '?'){
            t[i] = 'D';
        }
        if(t[i] == 'D'){
            ans += t[i-1] == 'P' ? 2 : 1;
        }
    }
    cout << t << endl;
}