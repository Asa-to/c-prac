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
    cout << (a <= b && b <= a * 6 ? "Yes" : "No") << endl;
}