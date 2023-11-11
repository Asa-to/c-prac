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
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    rep(i, q) {
        ll sum = 0;
        ll l, r;
        cin >> l >> r;
        l = l - 1;
        r = r - 1;
        string sub = s.substr(l, r - l + 1);
        char b = sub[0];
        for (int i = 1; i < sub.size(); i++) {
            if (b == sub[i]) {
                sum++;
            }
            b = sub[i];
        }
        cout << sum << endl;
    }
}
