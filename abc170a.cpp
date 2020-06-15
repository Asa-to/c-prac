#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    int a[5];
    rep(i,5)cin >> a[i];
    int n;
    rep(i, 5){
        if(a[i] == 0){
            if(i != 0){
                cout << a[i-1] + 1 << endl;
                return 0;
            }else{
                cout << a[i+1] - 1 << endl;
                return 0;
            }
        }
    }
}