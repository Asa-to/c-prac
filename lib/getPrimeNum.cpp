#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

int main(void){
}

/**
 * param {int} top
 * returns {int} top以下の最大の素数。存在しない場合は-1を返す。
**/
int getPrimeNum(int top){
    if(top <= 1){
        return -1;
    }
    for(int i = top; 1 < top; i--){
        bool flag = true;
        for(int j = 2; j <= pow(top, 0.5); j++){
            if(i % j == 0){
                flag = false;
                break;
            }
        }
        if(flag)return i;
    }
}