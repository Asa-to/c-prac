#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

int main(void){
    int n, m, c;
    cin >> n >> m >> c;
    int a[n][m], b[m];
    rep(i, m)cin >> b[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        int sum = c;
        for(int j = 0; j < m; j++){
            sum += a[i][j] * b[j];
        }
        if(sum > 0){
            count++;
        }
    }
    cout << count << endl;
}