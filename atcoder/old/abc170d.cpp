#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

bool is(int n){
    if(1 < n && n % 2 == 0)return false;
    for(int i = 2; i <= pow(n, 0.5); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> ok(n, true);
    rep(i, n){
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    rep(i, n){
        if(ok[i] && a[i] != a[i+1])ans++;
        for(int j = i+1; j < n; j++){
            if(!a[j])break;
            if(a[j] % a[i] == 0){
                ok[j] = false;
            }
        }
    }
    cout << ans << endl;
}