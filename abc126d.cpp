#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

#define MAX 100001
#define WHITE 0
#define BLACK 1
vector<vector<pair<int, int> > > G(MAX);
vector<int> colorList(MAX, -1);

void dfs(int v, ll distance){
    colorList[v] = distance % 2;
    // cout << v + 1 << " " << colorList[v] << endl;
    for(int i = 0; i < G[v].size(); i++){
        int next = G[v][i].first;
        ll next_distance = distance + G[v][i].second;
        if(colorList[next] != -1)continue;
        dfs(next, next_distance);
    }
}

int main(void){
    int n;
    cin >> n;
    int m = n - 1;
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        G[u].push_back(make_pair(v,w));
        G[v].push_back(make_pair(u,w));
    }
    dfs(0,0);
    for(int i = 0; i < n; i++){
        cout << colorList[i] << endl;
    }
}