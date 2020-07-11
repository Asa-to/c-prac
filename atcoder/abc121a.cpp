#include <bits/stdc++.h>

using namespace std;

#define rep(a, b) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

int main(void){
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    cout << H * W - h * W - w * H + h * w << endl;
}