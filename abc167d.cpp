#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

int main(void){
    int n;ll k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    int oks[n];
    for(int i = 0; i < n; i++)oks[i] = -1;
    int now = 0;
    for(int i = 0; i < k; i++){
        if(oks[now] != -1){
            k -= (oks[now]);
            k %= (i - oks[now]);
            i = -1;
            for(int i = 0; i < n; i++)oks[i] = -1;
            // cout << now << " " << k << endl;
            continue;
        }
        oks[now] = i;
        now = a[now];
    }
    cout << now + 1 << endl;
}