#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

int N;
vector<vector<int> > G;

int main(void){
    cin >> N;
    G.resize(N);
    //input
    for(int i = 0; i < N; i++){int a, b;cin >> a >> b;a--;b--;G[a].push_back(b);G[b].push_back(a);}
    int Q; cin >> Q;
    while(Q--){
        int u,v; cin >> u >> v; u--; v--;
    }
}