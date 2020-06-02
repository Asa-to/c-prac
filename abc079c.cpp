#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    string s;
    cin >> s;
    int a[4];
    rep(i,4)a[i] = stoi(s.substr(i,1));
    for(int bit = 0; bit < (1<<3); bit++){
        int sum = a[0];
        string ans = to_string(a[0]); 
        for(int i = 0; i < 3; i++){
            if(bit&(1<<i)){
                sum += a[i+1];
                ans += '+';
            }else{
                sum -= a[i+1];
                ans += '-';
            }
            ans += to_string(a[i+1]);
        }
        if(sum == 7){
            ans += "=7";
            cout << ans << endl;
            return 0;
        }
    }
}