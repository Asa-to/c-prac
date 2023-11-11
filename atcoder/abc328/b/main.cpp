#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
template <typename T>
bool chmax(T &a, T b) {
    if (a <= b) {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
bool chmin(T &a, T b) {
    if (a >= b) {
        a = b;
        return true;
    }
    return false;
}

int main(void) {
    ll n;
    cin >> n;
    vector<ll> d(n);
    rep(i, n) cin >> d[i];
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i < 10 || i % 11 == 0) {
            for (int j = 1; j <= d[i - 1]; j++) {
                if (j == i || i % 10 == j || j == i + i * 10) {
                    // cout << "i: " << i << " j: " << j << endl;
                    sum++;
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}
