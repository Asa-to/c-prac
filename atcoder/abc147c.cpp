#include<bits/stdc++.h>

using namespace std;

int n;
int A[20];
int x[20][20];
int y[20][20];

bool check(int bit){
    //全ての証言を調べていく
    //i番目の人の証言について調べる
    for(int i = 0; i < n; i++){
        //i番目の人が不親切想定なら、証言は全て無意味なのでスキップ
        if(!(bit & (1 << i)))continue;
        //i番目の人の証言jについて調べる
        for(int j = 0; j < A[i]; j++){
            //bit >> x[i][j]でx[i][j]番目を一番右において、1と論理積を取ることでほかの桁を全て0にする
            //^はXOR演算子、どちらか片方だけが1の場合0を、両方1、もしくは両方0の場合1を返す
            if(((bit >> x[i][j]) & 1) ^ y[i][j])return false;
        }
    }
    return true;
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        for(int j = 0; j < A[i]; j++){
            cin >> x[i][j] >> y[i][j];
            x[i][j]--;
        }
    }
    int maxj = 0;
    for(int bit = 0; bit < (1 << n); bit++){
        //このbitが真実の1つなら、立っているフラグの数を数える(正直者の数を数える)
        if(check(bit)){
            maxj = max(maxj,__builtin_popcount(bit));
        }
    }
    cout << maxj << endl;
}