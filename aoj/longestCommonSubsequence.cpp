#include<bits/stdc++.h>

using namespace std;
/*
* 最長共通部分列の長さを求めたい
* どういうことかとういと、文字列xと文字列yの間でいくつ共通の文字が存在するかということ。文字が連続している必要はない
*/

//Longest Common Subsequence の略
void lcs(string x, string y){
    //まずxとyの長さを取って、長さ分の容量を確保した二次元配列をつくる　
    int n = x.length();
    int m = y.length();
    int a[n+1][m+1];
    //配列の初期化
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            a[i][j] = 0;
        }
    }
    //1文字目に空白を挿入
    x = ' ' + x;
    y = ' ' + y;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(x[i] == y[j]){
                a[i][j] = a[i-1][j-1] + 1;
            }else if(a[i-1][j] >= a[i][j-1]){
                a[i][j] = a[i-1][j];
            }else{
                a[i][j] = a[i][j-1];
            }
        }
    }
    cout << a[n][m] << endl;
}

int main(void){
    int n;
    cin >> n;
    string x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        lcs(x, y);
    }
    return 0;
}