#include<bits/stdc++.h>

using namespace std;

void printdpTable(vector<vector<int> > a){
    cout << "- dp table -" << endl;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "- dp table -" << endl;
}

//すべての最長部分文字列をの長さ出力する
void printLcs(string x, string y){
    int n = x.length();
    int m = y.length();
    vector<vector<int> > a(n+1, vector<int>(m+1, 0));
    x = ' ' + x;
    y = ' ' + y;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(x[i] == y[j]){
                a[i][j] = a[i-1][j-1]+1;
            }else{
                a[i][j] = max(a[i-1][j], a[i][j-1]);
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
        printLcs(x,y);
    }
    return 0;
}