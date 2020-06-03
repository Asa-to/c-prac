#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

int main(void){
    vector<int> a(100);
    for(int i = 0; i < 100; i++){
        a[i] = 100;
    }
    vector<int> unko = a;
    unko[0] = 1;
    cout << a[0] << endl;
}