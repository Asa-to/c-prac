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
    ll x;
    cin >> x;
    if (x == 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << (x % 100 == 0 ? "Yes" : "No") << endl;
    return 0;
}