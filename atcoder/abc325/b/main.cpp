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
    vector<ll> w(n);
    vector<ll> x(n);
    rep(i, n) cin >> w.at(i) >> x.at(i);
    ll s = 0;
    rep(i, 24) {
        ll sum = 0;
        rep(j, n) {
            ll time = (x[j] + i) % 24;
            if (9 <= time && time < 18) {
                sum += w[j];
            }
        }
        chmax(s, sum);
    }
    cout << s << endl;
}
