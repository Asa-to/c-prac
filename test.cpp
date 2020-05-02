/*
* N個のあたえられた整数の中からいくつか選んで総和がWになる組み合わせの数を求める
*/
#include <bits/stdc++.h>

using namespace std;

//int 型整数値bitを2進数にして各桁をvector型の各インデックスに格納
vector<int> IntegerToVector(int bit, int N){
    vector<int> S;
    for(int i = 0; i < N; i++){
        if(bit & (1<<i)){
            S.push_back(i);
        }
    }
    return S;
}

int main(void){
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    //bit全探索で全ての組み合わせに対して和がWになるか調べる
    int ans = 0;
    for(int bit = 0; bit < (1<<N); bit++){
        int sum = 0;
        for(int i = 0; i < N; i++){
            if(bit & (1<<i))sum += a[i];
        }
        //和がWならansをインクリメントする
        if(sum == W)ans++;
    }
    cout << ans << endl;
}