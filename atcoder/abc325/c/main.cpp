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
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    vector<vector<bool>> check(h, vector<bool>(w, false));

    ll count = 0;
    rep(i, h) {
        rep(j, w) {
            if (!check[i][j] && s[i][j] == '#') {
                count++;
                for (ll k = 0; j + k < w && s[i][j + 1] == char('#'); k++) {
                    check[i][k] = true;
                }
                for (ll k = 0; i + k < h && s[i + k][j] == char('#'); k++) {
                    check[i + k][j] = true;
                }
                for (ll k = 0;
                     i + k < h && j + k < w && s[i + k][j + k] == char('#');
                     k++) {
                    check[i + k][j] = true;
                }
            }
        }
    }
    cout << count << endl;
}
