#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    int a, b, c;
    cin >> a >> b >> c;
    int count = 0;
    while(0 <= (b - a) && count < c){
        b -= a;
        count++;
    }
    cout << count << endl;
}