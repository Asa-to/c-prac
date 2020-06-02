#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    ll sum = 0;
    string s;
    cin >> s;
    for(int bit = 0; bit < (1<<s.length() - 1); bit++){
        int before = 0;
        for(int i = 0; i < s.length() - 1; i++){
            if(bit&(1<<i)){
                sum += stoll(s.substr(before, i + 1 - before));
                before = i + 1;
            }
        }
        sum += stoll(s.substr(before, s.length() - before));
    }
    cout << sum << endl;
}