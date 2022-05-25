#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

int main(void){
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    vector<int> b(K);
    int max = -1;
    rep(i, N) {
        cin >> a[i];
        chmax(max, a[i]);
    }
    rep(i, K) cin >> b[i];
    rep(i, K) {
        if (a[b[i]-1] == max) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}