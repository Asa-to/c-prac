#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a < b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b){a = b; return true;}return false;}

int main(void){
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for(int i = 0; i < 2; i++){
    if(a <= b){
        ans += b;
        b--;
    }else{
        ans += a;
        a--;
    }
    }
    cout << ans << endl;
}