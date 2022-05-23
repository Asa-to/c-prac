#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

#define WHITE 0
#define BLACK 1
vector<vector<pair<int, int> > > G;
vector<int> colorList;
vector<ll> distanceList;

void setDistance(int v, ll distance){
    distanceList[v] = distance;
    if(distance % 2 == 0){
        colorList[v] = WHITE;
    }else{
        colorList[v] = BLACK;
    }
    for(int i = 0; i < G[v].size(); i++){
        int next = G[v][i].first;
        if(distanceList[next])continue;
        setDistance(next, distance += G[v][i].second);
    }
}

int main(void){
    int n;
    cin >> n;
    G.resize(n);
    colorList.resize(n);
    distanceList.resize(n);
    int m = n - 1;
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        G[u].push_back(make_pair(v,w));
        G[v].push_back(make_pair(u,w));
    }
    setDistance(0,0);
    for(auto i: colorList){
        cout << i << endl;
    }
}