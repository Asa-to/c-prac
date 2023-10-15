#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
template <typename T>
bool chmax(T &a, T b) { if (a <= b) { a = b; return true; } return false; }
template <typename T> bool chmin(T &a, T b) { if (a >= b) { a = b; return true; } return false; }

int main(void) {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> c(n);
    rep(i, n) cin >> c[i];
    cout << distance(c.begin(), (find(c.begin(), c.end(), a + b)) + 1) << endl;
}
