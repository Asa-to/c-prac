#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

int lcs(string, string);

int main(void){
    string a, b;
    cin >> a >> b;
    cout << lcs(a, b) << endl;
    return 0;
}

/**
 * param{string} first string a
 * param{string} second string b
 * returns{int} lcs(a, b)
**/
int lcs(string a, string b){
    int n = a.length();
    int m = b.length();
    //1originのdp用配列cの宣言
    vector<vector<int> > c(n+1, vector<int>(m+1));
    //lcsのメイン処理
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j]){
                c[i][j] = c[i-1][j-1] + 1;
            }else if(a[i] != b[i]){
                chmax(c[i][j], max(c[i-1][j], c[i][j-1]));
            }
        }
    }
    return c[n][m];
}