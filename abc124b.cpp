#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

int main(void){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)cin >> a[i];
    int ans = 0;
    int highest = 0;
    for(int i = 0; i < n; i++){
        if(chmax(highest, a[i])){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}