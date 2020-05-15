#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

int main(void){
    int a, b, c, d, e, k;
    cin >> a >> b >> c >> d >> e >> k;
    if(e - a <= k){
        cout << "Yay!" << endl;
    }else{
        cout << ":(" << endl;
    }
}