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
    ll a, b;
    cin >> a >> b;
    if (0 < a && b == 0) {
        cout << "Gold" << endl;
        return 0;
    } else if (a == 0 && 0 < b) {
        cout << "Silver" << endl;
        return 0;
    } else {
        cout << "Alloy" << endl;
        return 0;
    }
}