#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    double ans = sqrt((double)25.0 - (double)24.0 * cos(60.0/180.0*M_PI));
    cout << fixed << ans << setprecision(10) << endl;
}