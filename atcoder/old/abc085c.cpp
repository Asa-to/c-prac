#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    int n, y;
    cin >> n >> y;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            int k = n - i - j;
            if(k < 0)break;
            if(1000 * i + 5000 * j + 10000 * k == y){
                cout << k << " " << j << " " << i << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
}