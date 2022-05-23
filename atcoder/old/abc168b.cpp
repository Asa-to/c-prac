#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    int k;
    string s;
    cin >> k >> s;
    if(s.length() <= k){
        cout << s << endl;
    }else{
        string str = s.substr(0, k);
        str += "...";
        cout << str << endl;
    }
}