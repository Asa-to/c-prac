#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    string s;
    cin >> s;
    int n = s.length();
    int n0 = 0, n1 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            n0++;
        }else{
            n1++;
        }
    }
    cout << min(n0, n1) * 2 << endl;
}