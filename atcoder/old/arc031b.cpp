#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

#define sea 'x'
#define rand 'o'

vector<string> c(10);
vector<vector<bool> > isSea(10,vector<bool>(10));
vector<vector<int> > islandCode(10,vector<int>(10));

const int dw[4] = {0,1,0,-1};
const int dh[4] = {1,0,-1,0};
void dfs(int h, int w, vector<vector<bool> > &memo, int id){
    memo[h][w] = true;
    islandCode[h][w] = id;
    for(int i = 0; i < 4; i++){
        int next_h = h + dh[i];
        int next_w = w + dw[i];
        //向かう先が地図の外でないか確認
        if(next_w < 0 || 10 <= next_w || next_h < 0 || 10 <= next_h)continue;
        //向かう先が海でないか確認
        if(c[next_h][next_w] == sea)continue;
        //向かう先が未探索か確認
        if(memo[next_h][next_w])continue;
        dfs(next_h, next_w, memo, id);
    }
}

int numIsrands() {
    int numIsrands = 0;
    vector<vector<bool> > memo = isSea;
    bool frag = true;
    int id = 0;
    for (int h = 0; h < 10; h++) {
        for (int w = 0; w < 10; w++) {
            if (!memo[h][w]) {
                numIsrands++;
                dfs(h, w, memo, ++id);

        //         cout << "--------memo---------" << endl;
        //         cout << h << " " << w << endl;
        //         for (int h = 0; h < 10; h++) {
        //             for (int w = 0; w < 10; w++) {
        //                 if (memo[h][w]) {
        //                     cout << sea;
        //                 } else {
        //                     cout << rand;
        //                 }
        //             }
        //             cout << endl;
        //         }
           }
        }
    }
    return numIsrands;
}

bool call(int numIsrand){
    for(int w = 0; w < 10; w++){
        for(int h = 0; h < 10; h++){
            if(isSea[h][w]){
                int numOfIsl = 0;
                set<int> id;
                for(int i = 0; i < 4; i++){
                    int next_h = h + dh[i];
                    int next_w = w + dw[i];
                    if(next_h < 0 || next_w < 0 || 10 <= next_h || 10 <= next_w)continue;
                    if(!isSea[next_h][next_w]){
                        if(id.find(islandCode[next_h][next_w]) != id.end())continue;
                        id.insert(islandCode[next_h][next_w]);
                        numOfIsl++;
                    }
                }
                if(numIsrand - numOfIsl == 0){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(void){
    rep(i,10){
        cin >> c[i];
        rep(j, 10)if(c[i][j] == sea)isSea[i][j] = true;
    }
    int numIsrand = numIsrands();
    if(numIsrand == 1){
        cout << "YES" << endl;
        return 0;
    }
    if(call(numIsrand)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    // cout << "---------------------"<<endl;
    // for(int h = 0; h < 10; h++){
    //     for(int w = 0; w < 10; w++){
    //         if(isSea[h][w]){
    //             cout << sea;
    //         }else{
    //             cout << rand;
    //         }
    //     }
    //     cout << endl;
    // }
}