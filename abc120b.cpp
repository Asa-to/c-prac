#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

int lcm(int a, int b){
    while(a % b != 0){
        int c = a % b;
        a = b;
        b = c;
    }
    return b;
}

int main(void){
    int a, b, k;
    cin >> a >> b >> k;
    int count = 0;
    for(int i = min(a, b); 0 < i; i--){
        if(a % i == 0 && b % i == 0){
            count++;
        }
        if(count == k){
            cout << i << endl;
            break;
        }
    }
}