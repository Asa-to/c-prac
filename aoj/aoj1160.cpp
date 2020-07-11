#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}
#define sea 0
#define rand 1

int W, H;
vector<vector<int> > c;
vector<vector<bool> > memo;

int dw[8] = {0,1,1,1,0,-1,-1,-1};
int dh[8] = {1,1,0,-1,-1,-1,0,1};
void dfs(int h, int w){
    memo[h][w] = true;
    for(int i = 0; i < 8; i++){
        int next_h = h + dh[i];
        int next_w = w + dw[i];
        //地図の範囲外でないかの確認
        if(next_w < 0 || next_h < 0 || W <= next_w || H <= next_h)continue;
        //行き先が見探索であるか確認
        if(memo[next_h][next_w])continue;
        dfs(next_h, next_w);
    }
}

main(void) {
    while (true) {
        cin >> W >> H;
        if(W + H == 0)break;
        memo.resize(H);
        rep(h,H){
            memo[h].resize(W);
            rep(w,W)memo[h][w] = false;
        }
        c.resize(H);
        for(int h = 0; h < H; h++){
            c[h].resize(W);
            for(int w = 0; w < W; w++){
                cin >> c[h][w];
                if(c[h][w] == sea)memo[h][w] = true;
            }
        }
        int ans = 0;
        rep(h,H){
            rep(w, W){
                if(!memo[h][w]){
                    dfs(h, w);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}