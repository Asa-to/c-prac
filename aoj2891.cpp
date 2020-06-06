#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

int N;
vector<vector<int> > G;

int dfs(int now, int depth,int parent, int target){
    cout << now << endl;
    if(now == target)return depth;
    int ans;
    for(int i = 0; i < G[now].size(); i++){
        int next = G[now][i];
        if(next == parent)continue;
        ans = dfs(next, ++depth, now, target);
    }
    return ans;
}

int main(void){
    cin >> N;
    G.resize(N);
    //input
    for(int i = 0; i < N; i++){int a, b;cin >> a >> b;a--;b--;G[a].push_back(b);G[b].push_back(a);}
    int Q; cin >> Q;
    while(Q--){
        int u,v; cin >> u >> v; u--; v--;
        cout << dfs(u, 0, -1, v) << endl;;
    }
}