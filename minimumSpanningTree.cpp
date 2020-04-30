#include<bits/stdc++.h>

using namespace std;

static const int INF = (1 << 21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n;
vector<vector<int>> m;

//T -> 最小全域木に属する頂点集合で、最終的に T = Vになる
//MST -> 最小全域木
int prim(){
    int u, minv;
    //
    vector<int> d(n, INF);
    //p[v]にMSTにおける頂点vの親を記録する
    vector<int> p(n, -1);
    //各頂点の訪問状態を記録する
    vector<int> color(n, WHITE);
    d[0] = 0;
    p[0] = -1;
    while(true){
        minv = INF;
        for(int i = 0; i < n; i++){
            if(color[i] != BLACK && d[i] < minv){
                minv = d[i];
                u = i;
            }
        }
        if(minv == INF){
            break;
        }
        color[u] = BLACK;
        for(int v = 0; v < n; v++){
            if(color[v] != BLACK && d[v] < minv){
                if( m[u][v] < d[v]){
                    d[v] = m[u][v];
                    p[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(p[i] != -1)sum += m[i][p[i]];
    }
    return sum;
}

int main(void){
    cin >> n;
    m.resize(n);
    for(int i = 0; i < n; i++){
        m[i].resize(n);
        for(int j = 0; j < n; j++){
            cin >> m[i][j];
            if(m[i][j] == -1)m[i][j] = INF;
        }
    }
    cout << prim() << endl;
    return 0;
}