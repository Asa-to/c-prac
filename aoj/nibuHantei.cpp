#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

#define NONE -1
#define BLACK 0
#define WHITE 1

int nextColor(int color){
    return color == BLACK ? WHITE : BLACK;
}

vector<int> colorList;
bool dfs(vector<vector<int> > G, int v, int color){
    colorList[v] = color;
    for(int i = 0; i < G[v].size(); i++){
        int next = G[v][i];
        if(colorList[next] != NONE){
            if (colorList[next] == color) return false;
            continue;
        }
        if(!dfs(G, next, nextColor(color)))return false;
    }
    return true;
}

int main(void){
    int N, M;
    cin >> N >> M;
    vector<vector<int> > G(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    colorList.resize(N);
    rep(i, N)colorList[i] = NONE;
    if(dfs(G, 0, BLACK)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}