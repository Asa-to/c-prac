#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

vector<string> c;
vector<vector<bool> > oks(501, vector<bool>(501));

int h, w;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y){
    oks[x][y] = true;
    for(int i = 0; i < 4; i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        //移動先が存在しなければ次へ
        if(next_x < 0 || h <= next_x || next_y < 0 || w <= next_y)continue;
        //移動先が壁なら次へ
        if(c[next_x][next_y] == '#')continue;
        //移動先に行ったことあれば次へ
        if(oks[next_x][next_y])continue;
        dfs(next_x, next_y);
    }
}

int main(void){
    cin >> h >> w;
    c.resize(h);
    oks.resize(h);
    rep(i, h)cin >> c[i];
    //家と魚屋の座標を探す
    int home_x, home_y, fish_x, fish_y;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(c[i][j] == 's'){
                home_x = i;
                home_y = j;
            }
            if(c[i][j] == 'g'){
                fish_x = i;
                fish_y = j;
            }
        }
    }
    dfs(home_x, home_y);
    if(oks[fish_x][fish_y]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}