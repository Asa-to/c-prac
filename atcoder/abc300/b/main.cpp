#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

int main(void) { 
    int h, w;
    cin >> h >> w;
    vector<string> a(w, "");
    vector<string> b(w * 2, "");

    rep(i, h) rep(j, w) {
        char temp;
        cin >> temp;
        a[i] += temp;
    }
    rep(i, h) rep(j, w) { 
        char temp;
        cin >> temp;
        b[i] += temp;
    }
    rep(i, h) b[i] += b[i];

    rep(i, h) {
        bool flag = true;
        if (b[i].find(a[i]) != string::npos) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
