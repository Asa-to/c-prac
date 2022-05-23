#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}


int main(void){
    double a, c, h, m;
    cin >> a >> c >> h >> m;
    double b;
    double jikan = (h / 12 + 1.0 / 12 * m / 60) * 360; 
    double hun = m / 60 * 360;
    double kaku = jikan < hun ? hun - jikan : jikan - hun;
    kaku = kaku / 180 * 3.141592;
    b = sqrt(pow(a,2) + pow(c,2) - 2*a*c*cos(kaku));
    cout << fixed << setprecision(10) << b << endl;
}