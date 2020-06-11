#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

int W, H;
vector<vector<bool> > seen(1005, vector<bool>(1005));
vector<int> dw = {0, 1, 0, -1};
vector<int> dh = {1, 0, -1, 0};
void dfs(int h, int w, vector<vector<int> > a){
    seen[h][w] = true;
    rep(i, 4){
        int nextH = h + dw[i];
        int nextW = w + dh[i];
        if(nextH < 0 || nextW < 0 || W <= nextW || H <= nextH)continue;
        if(seen[nextH][nextW])continue;
        if(!a[nextH][nextW])continue;
        dfs(nextH, nextW, a);
    }
}

int main(void){
    cin >> W >> H;
    // W × H
    vector<vector<int> > a(H, vector<int>(W));
    rep(i, H){
        rep(j, W){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(!seen[i][j] && a[i][j]){
                dfs(i, j , a);
                ans++;
            }
        }
    }
    // for(int i = 0; i < H; i++){
    //     for(int j = 0 ; j < W; j++){
    //         cout << (seen[i][j] ? 1 : 0) << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "----------------------------" << endl;
    // for(int i = 0; i < H; i++){
    //     for(int j = 0; j < W; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans << endl;
}