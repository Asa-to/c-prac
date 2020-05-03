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

struct Node{
    vector<int> a;
};

int main(void){
    Node a;
    a.a.push_back(1);
    cout << a.a.size() << endl;
}