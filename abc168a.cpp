#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    int n;
    cin >> n;
    if(n % 10 == 3){
        cout << "bon" << endl;
    }else if(n % 10 == 0 || n % 10 == 1 || n % 10 == 6 || n % 10 == 8){
        cout << "pon" << endl;
    }else{
        cout << "hon" << endl;
    }
}